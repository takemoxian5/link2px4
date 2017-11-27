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
	//变量申明
	u8 lcd_id[12];				//存放LCD ID字符串
	u8 ov7725_retry=0;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200

//	KEY_EXTI_Init();
//	LED_Init();					  //初始化LED
//	usmart_dev.init(84);		//初始化USMART
//	W25QXX_Init();				//初始化W25Q128
	
	TIM3_Int_Init(0xFFFF,8400-1);	//定时器时钟84M，分频系数8400，所以84M/8400=10Khz的计数频率
	
	//内存管理 软件运行时对计算机内存资源的分配和使用的技术。
	//主要目的是 高效、快速的分配，并在适当的时候释放和回收内存资源
//	my_mem_init(SRAMIN);		//初始化内部内存池 
//	my_mem_init(SRAMCCM);		//初始化CCM内存池
	
	//LCD初始化 
// 	LCD_Init();           //初始化LCD FSMC接口
//  sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组
//	LCD_Clear(WHITE);
//	POINT_COLOR=RED;      //画笔颜色：红色
//	
	//SD卡检测
	while(SD_Init())//检测不到SD卡
	{
		printf("\r\nNO SD Card\r\n");
		delay_ms(500);
//		LED0=!LED0;//DS0闪烁
	}
	show_sdcard_info();	//打印SD卡相关信息
	printf("\r\n SD Card OK\r\n");//检测SD卡成功
	
//	exfuns_init();				//为fatfs相关变量申请内存  
//  f_mount(fs[0],"0:",1); 		//挂载SD卡 

    FRESULT fr;
    FATFS fs;
    FIL fil;

	FRESULT result;
  
// 	result = f_mount(0, &fs);			/* Mount a logical drive */
//	if (result != FR_OK)   
//	{
//		printf("挂载文件系统失败 (%d)\r\n", result);
//	}
  while(1)
	{
	    /* Open or create a log file and ready to append */
 //   f_mount(&fs, "", 0);
 	/* 挂载文件系统 */

	result = f_mount(0, &fs);			/* Mount a logical drive */
	if (result != FR_OK)
	{
		printf("挂载文件系统失败 (%d)\r\n", result);
	}
    fr = open_append(&fil, "hanlele````2`33333333333333logfile.txt");
   
    if (fr == FR_OK)  printf("\r\n SD Card creat OK\r\n");//检测SD卡成功;
        
        	uint32_t cnt = 0;
        FILINFO FileInf;
        DIR DirInf; 
        uint8_t tmpStr[20];
/* 读取当前文件夹下的文件和目录 */
	printf("Name\t\tTyepe\t\tSize\r\n");
	for (cnt = 0; ;cnt++) 
	{
		result = f_readdir(&DirInf,&FileInf); 		/* 读取目录项，索引会自动下移 */
		if (result != FR_OK || FileInf.fname[0] == 0)
		{
			break;
		}
		
		if (FileInf.fname[0] == '.')
		{
			continue;
		}
		
		printf("%s", FileInf.fname);
		if (strlen(FileInf.fname) < 8)	/* 对齐 */
		{
			printf("\t\t");
		}
		else
		{
			printf("\t");
		}
		if (FileInf.fattrib == AM_DIR)
		{
			printf("目录\t\t");
		} 
		else 
		{
			printf("文件\t\t");
		}
		printf("%d\r\n", FileInf.fsize);
		sprintf((char *)tmpStr, "%d", FileInf.fsize);
	}
    /* Append a line */


    /* Close the file */
    f_close(&fil);	
  }
	
	//OV7725初始化
//	OV7725_GPIO_Config();
//	while(OV7725_Init() != SUCCESS)	//检测OV7725是否驱动成功
//	{
//		ov7725_retry++;
//		if(ov7725_retry>5)
//		{
//			printf("\r\nNO OV7725\r\n");	
//			while(1);
//		}
//	}
		/*根据摄像头参数组配置模式*/
//	OV7725_Special_Effect(cam_mode.effect);
//	/*光照模式*/
//	OV7725_Light_Mode(cam_mode.light_mode);
//	/*饱和度*/
//	OV7725_Color_Saturation(cam_mode.saturation);
//	/*光照度*/
//	OV7725_Brightness(cam_mode.brightness);
//	/*对比度*/
//	OV7725_Contrast(cam_mode.contrast);
//	/*特殊效果*/
//	OV7725_Special_Effect(cam_mode.effect);
//	
//	/*设置图像采样及模式大小*/
//	OV7725_Window_Set(cam_mode.cam_sx,
//														cam_mode.cam_sy,
//														cam_mode.cam_width,
//														cam_mode.cam_height,
//														cam_mode.QVGA_VGA);
	
	while(1)
	{
	}
}


