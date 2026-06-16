// frame_parser.h
#ifndef FRAME_PARSER_H
#define FRAME_PARSER_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_FRAME_LEN  256   // 根据实际最大帧长调整

typedef void (*frame_callback_t)(uint8_t *data, uint8_t len);

void parser_init(frame_callback_t cb);
void parser_reset(void);
void parser_put_byte(uint8_t data);

#endif