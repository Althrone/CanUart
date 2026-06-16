// main.c
#include "stm32f1xx_hal.h"
#include "ring_buffer.h"
#include "frame_parser.h"

// 硬件定义
#define RX_BUF_SIZE    1024
#define UART_TIMEOUT_MS 50   // 超过50ms无新数据则复位状态机

static uint8_t rx_dma_buf[RX_BUF_SIZE];
static ring_buffer_t rb;
static volatile uint32_t last_rx_tick = 0;
static volatile uint32_t sys_tick = 0;   // 由1ms定时器递增

// 串口2 DMA RX 配置
void uart_dma_init(void) {
    // 使能时钟等略...
    __HAL_RCC_USART2_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

    // 配置DMA1_Channel6 (USART2_RX)
    DMA_HandleTypeDef hdma_usart2_rx;
    hdma_usart2_rx.Instance = DMA1_Channel6;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_CIRCULAR;   // 循环模式
    HAL_DMA_Init(&hdma_usart2_rx);

    // 关联UART
    UART_HandleTypeDef huart2;
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.hdmarx = &hdma_usart2_rx;
    HAL_UART_Init(&huart2);

    // 启动DMA接收
    HAL_UART_Receive_DMA(&huart2, rx_dma_buf, RX_BUF_SIZE);
}

// 1ms定时器中断（例如TIM6）
void TIM6_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim6);
    sys_tick++;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM6) {
        // 空，仅用于维护sys_tick
    }
}

// 更新最后收到字节的时间戳（需在解析字节时调用）
static void update_rx_timestamp(void) {
    last_rx_tick = sys_tick;
}

// 检查超时，复位状态机（在主循环中调用）
static void check_timeout(void) {
    if ((sys_tick - last_rx_tick) > UART_TIMEOUT_MS) {
        parser_reset();
        // 可选：清空环形缓冲区中未处理的数据
        // 此处简单复位，避免残留数据干扰
    }
}

// 接收到完整帧的回调
void on_frame_received(uint8_t *data, uint8_t len) {
    // 在这里处理完整的数据帧
    // data[0]~data[len-1] 是完整帧
}

int main(void) {
    HAL_Init();
    // 配置系统时钟、GPIO等...

    // 初始化环形缓冲区
    ring_buffer_init(&rb, rx_dma_buf, RX_BUF_SIZE);

    // 初始化解析器，注册回调
    parser_init(on_frame_received);

    // 初始化UART DMA
    uart_dma_init();

    // 初始化1ms定时器（TIM6）
    // ... (HAL_TIM_Base_Init等，此处省略)

    // 获取DMA当前传输位置作为初始head
    // 注意：DMA_CIRCULAR模式下，需要外挂一个变量来记录DMA已写指针
    // 更通用的做法：利用DMA的CNDTR寄存器计算当前写入位置
    // 此处简化：在DMA传输完成中断中更新head，但为了精确，我们可以在主循环中读取DMA_CNDTR
    // 为清晰，演示一种可靠方法：
    uint32_t dma_last_pos = 0;

    while (1) {
        // 1. 获取DMA当前已经写到rx_dma_buf的索引（通过CNDTR反向计算）
        uint32_t dma_current_pos = RX_BUF_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart2_rx);
        if (dma_current_pos >= RX_BUF_SIZE) dma_current_pos = 0;

        // 2. 更新环形缓冲区的head（写入指针），DMA写入的最新位置
        rb.head = dma_current_pos;

        // 3. 读取并处理所有可用字节
        while (!ring_buffer_is_empty(&rb)) {
            uint8_t byte = ring_buffer_get(&rb);
            update_rx_timestamp();       // 记录有数据活动
            parser_put_byte(byte);       // 喂给状态机
        }

        // 4. 检查超时，防止状态机卡死
        check_timeout();

        // 5. 其他任务...
    }
}