// ring_buffer.h
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t *buffer;
    uint32_t size;
    volatile uint32_t head;   // 写入索引（由DMA中断更新）
    volatile uint32_t tail;   // 读取索引（由主循环更新）
} ring_buffer_t;

void ring_buffer_init(ring_buffer_t *rb, uint8_t *buf, uint32_t size);
bool ring_buffer_is_empty(ring_buffer_t *rb);
uint32_t ring_buffer_available(ring_buffer_t *rb);
uint8_t ring_buffer_get(ring_buffer_t *rb);

#endif