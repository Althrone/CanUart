/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32g0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32g0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern FDCAN_HandleTypeDef hfdcan1;
extern FDCAN_HandleTypeDef hfdcan2;
extern DMA_HandleTypeDef hdma_usart4_rx;
extern DMA_HandleTypeDef hdma_usart4_tx;
extern DMA_HandleTypeDef hdma_usart5_rx;
extern DMA_HandleTypeDef hdma_usart5_tx;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32G0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel 1 interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart4_tx);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 2 and channel 3 interrupts.
  */
void DMA1_Channel2_3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 0 */

  /* USER CODE END DMA1_Channel2_3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart4_rx);
  HAL_DMA_IRQHandler(&hdma_usart5_rx);
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 1 */

  /* USER CODE END DMA1_Channel2_3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 Ch4 to Ch7, DMA2 Ch1 to Ch5 and DMAMUX1 Overrun Interrupts.
  */
void DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQn 0 */

  /* USER CODE END DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart5_tx);
  /* USER CODE BEGIN DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQn 1 */

  /* USER CODE END DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQn 1 */
}

/**
  * @brief This function handles TIM16, FDCAN1_IT0 and FDCAN2_IT0 Interrupt.
  */
void TIM16_FDCAN_IT0_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_FDCAN_IT0_IRQn 0 */

  /* USER CODE END TIM16_FDCAN_IT0_IRQn 0 */
  HAL_FDCAN_IRQHandler(&hfdcan1);
  HAL_FDCAN_IRQHandler(&hfdcan2);
  /* USER CODE BEGIN TIM16_FDCAN_IT0_IRQn 1 */

  /* USER CODE END TIM16_FDCAN_IT0_IRQn 1 */
}

/**
  * @brief This function handles TIM17, FDCAN1_IT1 and FDCAN2_IT1 Interrupt.
  */
void TIM17_FDCAN_IT1_IRQHandler(void)
{
  /* USER CODE BEGIN TIM17_FDCAN_IT1_IRQn 0 */

  /* USER CODE END TIM17_FDCAN_IT1_IRQn 0 */
  HAL_FDCAN_IRQHandler(&hfdcan1);
  HAL_FDCAN_IRQHandler(&hfdcan2);
  /* USER CODE BEGIN TIM17_FDCAN_IT1_IRQn 1 */

  /* USER CODE END TIM17_FDCAN_IT1_IRQn 1 */
}

/**
  * @brief This function handles USART3, USART4, USART5, USART6, LPUART1 globlal Interrupts (combined with EXTI 28).
  */
void USART3_4_5_6_LPUART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_4_5_6_LPUART1_IRQn 0 */

  /* USER CODE END USART3_4_5_6_LPUART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  HAL_UART_IRQHandler(&huart4);
  HAL_UART_IRQHandler(&huart5);
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART3_4_5_6_LPUART1_IRQn 1 */

  /* USER CODE END USART3_4_5_6_LPUART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

extern HAL_StatusTypeDef HAL_FDCAN_RxMessageDMA(FDCAN_HandleTypeDef *hfdcan, uint32_t RxLocation);

/**
  * @brief  Rx FIFO 0 callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo0ITs indicates which Rx FIFO 0 interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Rx_Fifo0_Interrupts.
  * @retval None
  */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if(hfdcan == &hfdcan1)
  {
    if(RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE)
    {
      
    }
  }
  else if(hfdcan == &hfdcan2)
  {
    if(RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE)
    {
      FDCAN_RxHeaderTypeDef RxHeader;
      uint8_t RxData[8];
      // HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, RxData);
      // HAL_UART_Transmit(&huart4, "Hello World!\r\n", 14, 1000);
      HAL_FDCAN_RxMessageDMA(&hfdcan2, FDCAN_RX_FIFO0);
    }
  }
}

void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo1ITs)
{
  if(hfdcan == &hfdcan1)
  {
    if(RxFifo1ITs & FDCAN_IT_RX_FIFO1_NEW_MESSAGE)
    {

    }
  }
  else if(hfdcan == &hfdcan2)
  {
    if(RxFifo1ITs & FDCAN_IT_RX_FIFO1_NEW_MESSAGE)
    {
      
    }
  }
}

#define FDCAN_ELEMENT_MASK_STDID ((uint32_t)0x1FFC0000U) /* Standard Identifier         */
#define FDCAN_ELEMENT_MASK_EXTID ((uint32_t)0x1FFFFFFFU) /* Extended Identifier         */
#define FDCAN_ELEMENT_MASK_RTR   ((uint32_t)0x20000000U) /* Remote Transmission Request */
#define FDCAN_ELEMENT_MASK_XTD   ((uint32_t)0x40000000U) /* Extended Identifier         */
#define FDCAN_ELEMENT_MASK_ESI   ((uint32_t)0x80000000U) /* Error State Indicator       */
#define FDCAN_ELEMENT_MASK_TS    ((uint32_t)0x0000FFFFU) /* Timestamp                   */
#define FDCAN_ELEMENT_MASK_DLC   ((uint32_t)0x000F0000U) /* Data Length Code            */
#define FDCAN_ELEMENT_MASK_BRS   ((uint32_t)0x00100000U) /* Bit Rate Switch             */
#define FDCAN_ELEMENT_MASK_FDF   ((uint32_t)0x00200000U) /* FD Format                   */
#define FDCAN_ELEMENT_MASK_EFC   ((uint32_t)0x00800000U) /* Event FIFO Control          */
#define FDCAN_ELEMENT_MASK_MM    ((uint32_t)0xFF000000U) /* Message Marker              */
#define FDCAN_ELEMENT_MASK_FIDX  ((uint32_t)0x7F000000U) /* Filter Index                */
#define FDCAN_ELEMENT_MASK_ANMF  ((uint32_t)0x80000000U) /* Accepted Non-matching Frame */
#define FDCAN_ELEMENT_MASK_ET    ((uint32_t)0x00C00000U) /* Event type                  */

#define SRAMCAN_FLS_NBR                  (28U)         /* Max. Filter List Standard Number      */
#define SRAMCAN_FLE_NBR                  ( 8U)         /* Max. Filter List Extended Number      */
#define SRAMCAN_RF0_NBR                  ( 3U)         /* RX FIFO 0 Elements Number             */
#define SRAMCAN_RF1_NBR                  ( 3U)         /* RX FIFO 1 Elements Number             */
#define SRAMCAN_TEF_NBR                  ( 3U)         /* TX Event FIFO Elements Number         */
#define SRAMCAN_TFQ_NBR                  ( 3U)         /* TX FIFO/Queue Elements Number         */

#define SRAMCAN_FLS_SIZE            ( 1U * 4U)         /* Filter Standard Element Size in bytes */
#define SRAMCAN_FLE_SIZE            ( 2U * 4U)         /* Filter Extended Element Size in bytes */
#define SRAMCAN_RF0_SIZE            (18U * 4U)         /* RX FIFO 0 Elements Size in bytes      */
#define SRAMCAN_RF1_SIZE            (18U * 4U)         /* RX FIFO 1 Elements Size in bytes      */
#define SRAMCAN_TEF_SIZE            ( 2U * 4U)         /* TX Event FIFO Elements Size in bytes  */
#define SRAMCAN_TFQ_SIZE            (18U * 4U)         /* TX FIFO/Queue Elements Size in bytes  */

#define SRAMCAN_FLSSA ((uint32_t)0)                                                      /* Filter List Standard Start
                                                                                            Address                  */
#define SRAMCAN_FLESA ((uint32_t)(SRAMCAN_FLSSA + (SRAMCAN_FLS_NBR * SRAMCAN_FLS_SIZE))) /* Filter List Extended Start
                                                                                            Address                  */
#define SRAMCAN_RF0SA ((uint32_t)(SRAMCAN_FLESA + (SRAMCAN_FLE_NBR * SRAMCAN_FLE_SIZE))) /* Rx FIFO 0 Start Address  */
#define SRAMCAN_RF1SA ((uint32_t)(SRAMCAN_RF0SA + (SRAMCAN_RF0_NBR * SRAMCAN_RF0_SIZE))) /* Rx FIFO 1 Start Address  */
#define SRAMCAN_TEFSA ((uint32_t)(SRAMCAN_RF1SA + (SRAMCAN_RF1_NBR * SRAMCAN_RF1_SIZE))) /* Tx Event FIFO Start
                                                                                            Address */
#define SRAMCAN_TFQSA ((uint32_t)(SRAMCAN_TEFSA + (SRAMCAN_TEF_NBR * SRAMCAN_TEF_SIZE))) /* Tx FIFO/Queue Start
                                                                                            Address                  */
#define SRAMCAN_SIZE  ((uint32_t)(SRAMCAN_TFQSA + (SRAMCAN_TFQ_NBR * SRAMCAN_TFQ_SIZE))) /* Message RAM size         */

static const uint8_t DLCtoBytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

// 定义状态机
typedef enum {
    RX_STATE_WAIT_HEADER,   // 等待接收帧头(8字节)
    RX_STATE_WAIT_DATA      // 等待接收数据载荷
} RxState_t;

#define BUFFER_SIZE (72*2*2)//canfd最长数据段64字节，帧头8字节，共72字节，留两帧空间
RxState_t rx_state = RX_STATE_WAIT_HEADER;
uint32_t can_frame_pos =0;//准备放到can tx fifo的帧的头地址
extern uint8_t uartRxData[BUFFER_SIZE];

uint8_t can_is_transfering = 0;

extern  HAL_StatusTypeDef HAL_FDCAN_AddMessageToTxFifoQ_Raw(FDCAN_HandleTypeDef *hfdcan, uint32_t can_frame_pos, uint8_t frame_len);

uint32_t BufferUnsentLen(uint32_t head_index, uint32_t tail_index)
{
  if (tail_index >= head_index)
  {
    return (tail_index - head_index);
  }
  else
  {
    return (BUFFER_SIZE - head_index + tail_index);
  }
}

uint8_t ParseCanDataLen(uint32_t head_index)
{
  if(head_index + 6 < BUFFER_SIZE) {
    return DLCtoBytes[uartRxData[head_index + 6]&0x0F];
  }
  else {
    return DLCtoBytes[uartRxData[(head_index + 6) % BUFFER_SIZE]&0x0F];
  }
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
  if(huart != &huart4) return;

  HAL_UART_RxEventTypeTypeDef rx_event_type = HAL_UARTEx_GetRxEventType(&huart4);
  switch (rx_event_type)
  {
  case HAL_UART_RXEVENT_TC:
    /* code */
    break;
  case HAL_UART_RXEVENT_HT:
    /* code */
    break;
  case HAL_UART_RXEVENT_IDLE:
    /* code */
    break;
  
  default:
    break;
  }
  
  if(can_is_transfering) return;

  // 1. 获取当前 DMA 写位置和未读数据长度
  uint32_t dma_cur_pos = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart4_rx);
  uint32_t unread = BufferUnsentLen(can_frame_pos, dma_cur_pos);

  // 至少要有帧头（8字节）才能继续
  if (unread < 8) return;

  // 2. 解析帧长
  uint32_t frame_len = ParseCanDataLen(can_frame_pos);
  uint32_t total_needed = 8 + frame_len;

  // 3. 再次获取最新 DMA 位置（因为刚才解析期间可能又有新数据到达）
  dma_cur_pos = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart4_rx);
  unread = BufferUnsentLen(can_frame_pos, dma_cur_pos);

  // 4. 检查是否完整
  if (unread >= total_needed) {
    // 发送帧
    if (HAL_FDCAN_AddMessageToTxFifoQ_Raw(&hfdcan2, can_frame_pos, frame_len) == HAL_OK) {
      can_is_transfering = 1;
      // 移动读指针
      can_frame_pos = (can_frame_pos + total_needed) % BUFFER_SIZE;
    } else {
        // 发送失败，保留当前帧，不清除 can_is_transfering
        // 可设置一个重试标志，主循环中处理
        while (1);
    }
  }
}

void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes)
{
  if (hfdcan != &hfdcan2) return;

  // 上一帧发送完成，清除发送标志
  can_is_transfering = 0;

  // 1. 获取当前 DMA 写位置和未读数据长度
  uint32_t dma_cur_pos = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart4_rx);
  uint32_t unread = BufferUnsentLen(can_frame_pos, dma_cur_pos);

  // 至少要有帧头（8字节）才能继续
  if (unread < 8) return;

  // 2. 解析帧长
  uint32_t frame_len = ParseCanDataLen(can_frame_pos);
  uint32_t total_needed = 8 + frame_len;

  // 3. 再次获取最新 DMA 位置（因为刚才解析期间可能又有新数据到达）
  dma_cur_pos = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart4_rx);
  unread = BufferUnsentLen(can_frame_pos, dma_cur_pos);

  // 4. 检查是否完整
  if (unread >= total_needed) {
    // 发送帧
    if (HAL_FDCAN_AddMessageToTxFifoQ_Raw(&hfdcan2, can_frame_pos, frame_len) == HAL_OK) {
      can_is_transfering = 1;
      // 移动读指针
      can_frame_pos = (can_frame_pos + total_needed) % BUFFER_SIZE;
    } else {
        // 发送失败，保留当前帧，不清除 can_is_transfering
        // 可设置一个重试标志，主循环中处理
        while (1);
    }
  }
}

/* USER CODE END 1 */
