// // frame_parser.c
// #include "frame_parser.h"

// typedef enum {
//     WAIT_LEN_BYTE,   // 等待接收第8个字节（长度）
//     RECV_DATA        // 正在接收数据
// } parser_state_t;

// static parser_state_t state = WAIT_LEN_BYTE;
// static uint8_t frame_buf[MAX_FRAME_LEN];
// static uint8_t buf_idx = 0;
// static uint8_t frame_len = 0;
// static frame_callback_t callback = NULL;

// void parser_init(frame_callback_t cb) {
//     callback = cb;
//     parser_reset();
// }

// void parser_reset(void) {
//     state = WAIT_LEN_BYTE;
//     buf_idx = 0;
//     frame_len = 0;
// }

// void parser_put_byte(uint8_t data) {
//     switch (state) {
//         case WAIT_LEN_BYTE:
//             frame_buf[buf_idx++] = data;
//             if (buf_idx == 8) {
//                 frame_len = data;   // 第8字节即总长度
//                 if (frame_len >= 8 && frame_len <= MAX_FRAME_LEN) {
//                     if (frame_len == 8) {
//                         // 正好8字节的一帧
//                         if (callback) callback(frame_buf, frame_len);
//                         parser_reset();
//                     } else {
//                         state = RECV_DATA;
//                     }
//                 } else {
//                     // 长度非法，丢弃这一帧并复位
//                     parser_reset();
//                 }
//             }
//             break;

//         case RECV_DATA:
//             frame_buf[buf_idx++] = data;
//             if (buf_idx == frame_len) {
//                 if (callback) callback(frame_buf, frame_len);
//                 parser_reset();
//             }
//             break;
//     }
// }