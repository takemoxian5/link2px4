#include "usart.h"	

#include "fifo.h"

fifo_t uart_rx_fifo, uart_tx_fifo;
uint8_t uart_tx_buf[UART_TX_BUFFER_SIZE], uart_rx_buf[UART_RX_BUFFER_SIZE];

///* Private function prototypes -----------------------------------------------*/
//#ifdef __GNUC__
//  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
//     set to 'Yes') calls __io_putchar() */
//  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#else
//  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#endif /* __GNUC__ */
////////////////////////////////////////////////////////////////////
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{ 	
	while((USART2->SR&0X40)==0);//ѭ������,ֱ���������   
	USART2->DR = (u8) ch;      
	return ch;
}
#endif
  
/* Private functions ---------------------------------------------------------*/

void USART1_Gpio_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);     //tx
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);     //rx

}

void USART2_Gpio_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);     //tx
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);     //rx

}

void USART3_Gpio_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);        //tx
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);        //rx
}

/*
 * USART1 is used for receiving commands from PC and
 * printing debug information to PC
 */
void USART1_Config(void)
{
  USART1_Gpio_Config();

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  USART_InitTypeDef USART_InitStructure;

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART1, &USART_InitStructure);
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

  USART_Cmd(USART1, ENABLE);

  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET)
    ;
}

/*
 * USART2 is used for receiving commands from PC and
 * printing debug information to PC
 */
void USART2_Config(void)
{
  USART2_Gpio_Config();

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  USART_InitTypeDef USART_InitStructure;

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART2, &USART_InitStructure);
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

  USART_Cmd(USART2, ENABLE);

  while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) != SET)
    ;
}

/*
 * USART3 is used for communicating with the DJI flight controller
 * The Baud rate needs to match the Baud rate used by the flight controller
 */
void USART3_Config(void)
{
  USART3_Gpio_Config();

  USART_InitTypeDef USART_InitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART3, &USART_InitStructure);
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

  USART_Cmd(USART3, ENABLE);
  while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) != SET)
    ;

}

void USARTxNVIC_Config()
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

  NVIC_InitTypeDef NVIC_InitStructure_USART3;
  NVIC_InitStructure_USART3.NVIC_IRQChannelPreemptionPriority = 0x02;
  NVIC_InitStructure_USART3.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure_USART3.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure_USART3.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure_USART3);

  NVIC_InitTypeDef NVIC_InitStructure_USART2;
  NVIC_InitStructure_USART2.NVIC_IRQChannelPreemptionPriority = 0x03;
  NVIC_InitStructure_USART2.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure_USART2.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure_USART2.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure_USART2);
	
  NVIC_InitTypeDef NVIC_InitStructure_USART1;
  NVIC_InitStructure_USART1.NVIC_IRQChannelPreemptionPriority = 0x04;
  NVIC_InitStructure_USART1.NVIC_IRQChannelSubPriority = 0x04;
  NVIC_InitStructure_USART1.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure_USART1.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure_USART1);	
}

void UsartConfig()
{
	USART1_Config();
  USART2_Config();
  USART3_Config();
  USARTxNVIC_Config();
}
void UART_send_byte(uint8_t byte) 							//����1�ֽ�����
{
 while(!((USART2->SR)&(1<<7)));
 USART2->DR=byte;	
}		

void UART_Send(uint8_t *Buffer, uint32_t Length)
{
	while(Length != 0)
	{
		while(!((USART2->SR)&(1<<7)));							//�ȴ�������
		USART2->DR = *Buffer;
		Buffer++;
		Length--;
	}
}

uint8_t UART_Recive(void)
{	
	while(!(USART2->SR & (1<<5)));								//�ȴ����յ�����
	return(USART2->DR);			 										//��������
}



//========================================================================================================
//���ڷ�װ�����ݻ�����
//========================================================================================================
/** @brief ���ڳ�ʼ��
  *        1) �����������ݻ�������һ�����ڷ��䣬һ�����ڽ���
  *        2) ��ʼ�����ڲ����ʣ�ȫ˫����ʹ�ܽ����ж�(�����жϣ��������ݷ����ʹ��)
  */
void serial_open(uint8_t port, uint32_t baud) {
	fifo_init(&uart_tx_fifo, uart_tx_buf, UART_TX_BUFFER_SIZE);	
	fifo_init(&uart_rx_fifo, uart_rx_buf, UART_RX_BUFFER_SIZE);
	
  UsartConfig();
}


/** @brief д���ݵ����ڣ��������
  *        
  * @note ����д�뷢�仺��������������жϣ����жϳ��������Զ�����
  */
uint8_t serial_write_buf(uint8_t* buf, uint16_t length) {
	uint16_t i;
	
	if(length == 0) return false;
  for(i = 0; length > 0; length--, i++)	{
		fifo_write_ch(&uart_tx_fifo, buf[i]);
	}	
  USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
	
	return true;
}

/** @brief �Դ��ڶ����� 
  * @return һ�ֽ�����
  */
uint8_t serial_read_ch(void){
	uint8_t ch;	
	fifo_read_ch(&uart_rx_fifo, &ch);	
	return ch;
}

/** @breif ��ⷢ�仺����ʣ���ֽڳ��� 
  * @return ʣ���ֽڳ���
  */
uint16_t serial_free(void){
	return fifo_free(&uart_tx_fifo);
}

uint16_t serial_available(void){
	return fifo_used(&uart_rx_fifo);
}
void USART2_IRQHandler(void)
{			
  uint8_t c;
	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
  {
		c = USART2->DR;		
		fifo_write_ch(&uart_rx_fifo, c);
		
    //USART_ITConfig(USART2, USART_IT_RXNE, DISABLE);
  }

  if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
  {   		
		if(fifo_read_ch(&uart_tx_fifo, &c)) USART2->DR = c;
		else USART2->DR = 0x55;
				
    if (fifo_used(&uart_tx_fifo) == 0)              // Check if all data is transmitted . if yes disable transmitter UDRE interrupt
    {
      // Disable the EVAL_COM1 Transmit interrupt 
      USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
    }
  }		
}

		

