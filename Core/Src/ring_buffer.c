// // ring_buffer.c
// #include "ring_buffer.h"

// void ring_buffer_init(ring_buffer_t *rb, uint8_t *buf, uint32_t size) {
//     rb->buffer = buf;
//     rb->size = size;
//     rb->head = 0;
//     rb->tail = 0;
// }

// bool ring_buffer_is_empty(ring_buffer_t *rb) {
//     return rb->head == rb->tail;
// }

// uint32_t ring_buffer_available(ring_buffer_t *rb) {
//     if (rb->head >= rb->tail)
//         return rb->head - rb->tail;
//     else
//         return rb->size - rb->tail + rb->head;
// }

// uint8_t ring_buffer_get(ring_buffer_t *rb) {
//     uint8_t data = rb->buffer[rb->tail];
//     rb->tail = (rb->tail + 1) % rb->size;
//     return data;
// }