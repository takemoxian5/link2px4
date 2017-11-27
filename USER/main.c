#include "sys.h"
#include "delay.h"
#include "usart.h"
//#include "led.h"
//#include "key.h"
//#include "lcd.h"
//#include "ov7725.h"
#include "timer.h"
//#include "malloc.h"
#include "sdio_sdcard.h"
//#include "usmart.h"
//#include "w25qxx.h"
#include "ff.h"
//#include "exfuns.h"
//#include "bmp.h"

//extern OV7725_MODE_PARAM cam_mode;
unsigned int black_num[9];
unsigned int frame_num=0;
uint32_t sample_time=0;

FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* path    /* [IN]  File name to be opened */
)
{
    FRESULT fr;

    /* Opens an existing file. If not exist, creates a new file. */
    fr = f_open(fp, path, FA_WRITE | FA_OPEN_ALWAYS);
    if (fr == FR_OK) {
        /* Seek to end of the file to append data */
        fr = f_lseek(fp, f_size(fp));
        if (fr != FR_OK)
            f_close(fp);
    }
    return fr;
}


/*
//int main (void)
//{
//    FRESULT fr;
//    FATFS fs;
//    FIL fil;

//    /* Open or create a log file and ready to append */
//    f_mount(&fs, "", 0);
//    fr = open_append(&fil, "logfile.txt");
//    if (fr != FR_OK) return 1;

//    /* Append a line */
//    f_printf(&fil, "%02u/%02u/%u, %2u:%02u\n", Mday, Mon, Year, Hour, Min);

//    /* Close the file */
//    f_close(&fil);

//    return 0;
//}

int main(void)
{ 
	//��������
	u8 lcd_id[12];				//���LCD ID�ַ���
	u8 ov7725_retry=0;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200

//	KEY_EXTI_Init();
//	LED_Init();					  //��ʼ��LED
//	usmart_dev.init(84);		//��ʼ��USMART
//	W25QXX_Init();				//��ʼ��W25Q128
	
	TIM3_Int_Init(0xFFFF,8400-1);	//��ʱ��ʱ��84M����Ƶϵ��8400������84M/8400=10Khz�ļ���Ƶ��
	
	//�ڴ���� �������ʱ�Լ�����ڴ���Դ�ķ����ʹ�õļ�����
	//��ҪĿ���� ��Ч�����ٵķ��䣬�����ʵ���ʱ���ͷźͻ����ڴ���Դ
//	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ�� 
//	my_mem_init(SRAMCCM);		//��ʼ��CCM�ڴ��
	
	//LCD��ʼ�� 
// 	LCD_Init();           //��ʼ��LCD FSMC�ӿ�
//  sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id����
//	LCD_Clear(WHITE);
//	POINT_COLOR=RED;      //������ɫ����ɫ
//	
	//SD�����
	while(SD_Init())//��ⲻ��SD��
	{
		printf("\r\nNO SD Card\r\n");
		delay_ms(500);
//		LED0=!LED0;//DS0��˸
	}
	show_sdcard_info();	//��ӡSD�������Ϣ
	printf("\r\n SD Card OK\r\n");//���SD���ɹ�
	
//	exfuns_init();				//Ϊfatfs��ر��������ڴ�  
//  f_mount(fs[0],"0:",1); 		//����SD�� 

    FRESULT fr;
    FATFS fs;
    FIL fil;

	FRESULT result;
  
// 	result = f_mount(0, &fs);			/* Mount a logical drive */
//	if (result != FR_OK)   
//	{
//		printf("�����ļ�ϵͳʧ�� (%d)\r\n", result);
//	}
  while(1)
	{
	    /* Open or create a log file and ready to append */
 //   f_mount(&fs, "", 0);
 	/* �����ļ�ϵͳ */

	result = f_mount(0, &fs);			/* Mount a logical drive */
	if (result != FR_OK)
	{
		printf("�����ļ�ϵͳʧ�� (%d)\r\n", result);
	}
    fr = open_append(&fil, "hanlele````2`33333333333333logfile.txt");
   
    if (fr == FR_OK)  printf("\r\n SD Card creat OK\r\n");//���SD���ɹ�;
        
        	uint32_t cnt = 0;
        FILINFO FileInf;
        DIR DirInf; 
        uint8_t tmpStr[20];
/* ��ȡ��ǰ�ļ����µ��ļ���Ŀ¼ */
	printf("Name\t\tTyepe\t\tSize\r\n");
	for (cnt = 0; ;cnt++) 
	{
		result = f_readdir(&DirInf,&FileInf); 		/* ��ȡĿ¼��������Զ����� */
		if (result != FR_OK || FileInf.fname[0] == 0)
		{
			break;
		}
		
		if (FileInf.fname[0] == '.')
		{
			continue;
		}
		
		printf("%s", FileInf.fname);
		if (strlen(FileInf.fname) < 8)	/* ���� */
		{
			printf("\t\t");
		}
		else
		{
			printf("\t");
		}
		if (FileInf.fattrib == AM_DIR)
		{
			printf("Ŀ¼\t\t");
		} 
		else 
		{
			printf("�ļ�\t\t");
		}
		printf("%d\r\n", FileInf.fsize);
		sprintf((char *)tmpStr, "%d", FileInf.fsize);
	}
    /* Append a line */


    /* Close the file */
    f_close(&fil);	
  }
	
	//OV7725��ʼ��
//	OV7725_GPIO_Config();
//	while(OV7725_Init() != SUCCESS)	//���OV7725�Ƿ������ɹ�
//	{
//		ov7725_retry++;
//		if(ov7725_retry>5)
//		{
//			printf("\r\nNO OV7725\r\n");	
//			while(1);
//		}
//	}
		/*��������ͷ����������ģʽ*/
//	OV7725_Special_Effect(cam_mode.effect);
//	/*����ģʽ*/
//	OV7725_Light_Mode(cam_mode.light_mode);
//	/*���Ͷ�*/
//	OV7725_Color_Saturation(cam_mode.saturation);
//	/*���ն�*/
//	OV7725_Brightness(cam_mode.brightness);
//	/*�Աȶ�*/
//	OV7725_Contrast(cam_mode.contrast);
//	/*����Ч��*/
//	OV7725_Special_Effect(cam_mode.effect);
//	
//	/*����ͼ�������ģʽ��С*/
//	OV7725_Window_Set(cam_mode.cam_sx,
//														cam_mode.cam_sy,
//														cam_mode.cam_width,
//														cam_mode.cam_height,
//														cam_mode.QVGA_VGA);
	
	while(1)
	{
	}
}


