#ifndef __USART_H
#define __USART_H
#include "stm32f4xx_conf.h"
//#include "stm32f0xx.h"
#include <stdio.h>

#define UART_TX_BUFFER_SIZE        255
#define UART_RX_BUFFER_SIZE        255
#define USART_REC_LEN  			200  	//定义最大接收字节数 200
void serial_open(uint8_t port, uint32_t baud);
u8 serial_write_buf(uint8_t* buf, uint16_t length);
u8 serial_read_ch(void);
u16 serial_free(void);
u16 serial_available(void);

#endif /* __USART_H */



