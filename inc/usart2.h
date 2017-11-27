#ifndef __USART2_H
#define __USART2_H

#include "board.h"

#define MAVLINK_BUFFER_SIZE    255

void 	mavlink_usart_init(uint32_t baudRate);
void 	mavlink_buf_swap(void);
void 	mavlink_usart_send_byte(u8 ch);
void    uart4_init();
int     putchar1 (int c);

#endif //__USART2_H
