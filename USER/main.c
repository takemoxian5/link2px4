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
#include "stdio.h"
#include <string.h>

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
static void SD_CARD_INIT(void)
{
SDIO_Interrupts_Config();	/* 配置SDIO中断， 此函数在bsp_sdio_sd.c */
//SD卡检测
while(SD_Init())//检测不到SD卡
{
	printf("\r\nNO SD Card\r\n");
	delay_ms(500);

}
show_sdcard_info(); //打印SD卡相关信息
printf("\r\n SD Card OK\r\n");//检测SD卡成功
}

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	TIM3_Int_Init(0xFFFF,8400-1);	//��ʱ��ʱ��84M����Ƶϵ��8400������84M/8400=10Khz�ļ���Ƶ��
	printf("STM32F4Discovery Board initialization finished!\r\n");

	//sd 初始化
FRESULT result;
FATFS fs;
DIR DirInf;
FILINFO FileInf;
FIL fil;
char* file_name="/hl5201314.txt";
char* file_path="/YX1288";
char textFileBuffer[100];
char file_name_path[100];
char textFileBuffer2[200];
u32 bw;
SD_CARD_INIT();
				/* 挂载文件系统 */
			   result = f_mount(0, &fs);		   /* Mount a logical drive */
			   if (result != FR_OK)
			   {
				   printf("挂载文件系统失败 (%d)\r\n", result);
			   }
			   /* 创建目录/  */
			   result = f_mkdir(file_path);
			   result=f_mount(0, &fs);
			   /* 打开根文件夹 */
			   result = f_opendir(&DirInf, file_path); /* 如果不带参数，则从当前目录开始 */
			   if (result != FR_OK)
			   {
				   printf("打开根目录失败 (%d)\r\n", result);
			   }
						   /* 打开文件 */
						   /*FA_OPEN_ALWAYS   | 打开文件，如果文件不存在，则创建一个新文件；| 用此种方式，可以用 f_lseek 在文件后追加数据
							   FA_CREATE_NEW   | 新建文件，如果文件已存在，则新建失败*/
			   //	   file_name_path=file_path+file_name;
			   //	 strcpy(file_name_path,file_path);
			   //	 strcat(file_name_path,file_name);
						   sprintf( file_name_path,    "%s%s",file_path,file_name);
						   printf("打开目录 (%s)\r\n", file_name_path);
						   result = f_open(&fil, file_name_path, FA_OPEN_ALWAYS | FA_WRITE);
			   
						   if(result!=FR_OK)
						   {
							   while(1);
						   }
						   result = f_lseek (&fil, fil.fsize);	////指针指向文件末尾
						   /* 写一串数据 */
						   sprintf( textFileBuffer,    "\r\lele128-FatFS Write Demo ");
			   
						   result = f_write(&fil, textFileBuffer, strlen(textFileBuffer)-1, &bw);
						   sprintf( textFileBuffer,    "\r\n2222222222222222222222222222-FatFS Write Demo ");
						   result = f_lseek (&fil, fil.fsize);	////指针指向文件末尾
						   result = f_write(&fil, textFileBuffer, strlen(textFileBuffer)-1, &bw);
						   sprintf( textFileBuffer,    "\r\n144444444444444444444-FatFS Write Demo ");
						   result = f_lseek (&fil, fil.fsize);	////指针指向文件末尾
						   result = f_write(&fil, textFileBuffer, strlen(textFileBuffer)-1, &bw);
						   /* 关闭文件*/
						   f_close(&fil);
						   /* 打开文件 */
						   result = f_open(&fil, file_name_path, FA_OPEN_EXISTING | FA_READ);
						   /* 读取文件 */
						   result = f_read(&fil, textFileBuffer2, fil.fsize,&bw);
						   if (bw > 0)
						   {
							   textFileBuffer2[bw] = 0;
							   printf("\r\narmfly.txt 文件内容 : \r\n%s\r\n", textFileBuffer2);
						   }
						   else
						   {
							   printf("\r\narmfly.txt 文件内容 : \r\n");
						   }
//						   delete [] textFileBuffer2;
						   f_close(&fil);
						   /* 卸载文件系统 */
						   f_mount(0, NULL);



  while(1)
	{

	result = f_mount(0, &fs);			/* Mount a logical drive */
	if (result != FR_OK)
	{
		printf("�����ļ�ϵͳʧ�� (%d)\r\n", result);
	}
    result = open_append(&fil, "128hanlele````2`33333333333333logfile.txt");
   
    if (result == FR_OK)  printf("\r\n SD Card creat OK\r\n");//���SD���ɹ�;
        
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
	while(1)
	{
	}
}


