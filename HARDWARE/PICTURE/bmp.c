#include "bmp.h"
#include "ff.h"
#include "lcd.h"
#include "usart.h"


FIL bmpfsrc, bmpfdst; 
FRESULT bmpres;

/**
 * @brief  ����LCD�Ľ�ȡBMPͼƬ
 * @param  x ����ȡ��������X���� 
 * @param  y ����ȡ��������Y���� 
 * @param  Width ��������
 * @param  Height ������߶� 
 * @retval ��
  *   �ò���Ϊ����ֵ֮һ��
  *     @arg 0 :��ͼ�ɹ�
  *     @arg -1 :��ͼʧ��
 */
int Screen_Shot( uint16_t x, uint16_t y, uint16_t Width, uint16_t Height, char * filename)
{
	/* bmp  �ļ�ͷ 54���ֽ� */
	unsigned char header[54] =
	{
		0x42, 0x4d, 0, 0, 0, 0, 
		0, 0, 0, 0, 54, 0, 
		0, 0, 40,0, 0, 0, 
		0, 0, 0, 0, 0, 0, 
		0, 0, 1, 0, 24, 0, 
		0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 
		0, 0, 0
	};
	
	int i;
	int j;
	long file_size;     
	long width;
	long height;
	unsigned char r,g,b;	
	unsigned int mybw;
	unsigned int read_data;
	char kk[4]={0,0,0,0};
	
	uint8_t ucAlign;//
	
	
	/* ��*�� +������ֽ� + ͷ����Ϣ */
	file_size = (long)Width * (long)Height * 3 + Height*(Width%4) + 54;		

	/* �ļ���С 4���ֽ� */
	header[2] = (unsigned char)(file_size &0x000000ff);
	header[3] = (file_size >> 8) & 0x000000ff;
	header[4] = (file_size >> 16) & 0x000000ff;
	header[5] = (file_size >> 24) & 0x000000ff;
	
	/* λͼ�� 4���ֽ� */
	width=Width;	
	header[18] = width & 0x000000ff;
	header[19] = (width >> 8) &0x000000ff;
	header[20] = (width >> 16) &0x000000ff;
	header[21] = (width >> 24) &0x000000ff;
	
	/* λͼ�� 4���ֽ� */
	height = Height;
	header[22] = height &0x000000ff;
	header[23] = (height >> 8) &0x000000ff;
	header[24] = (height >> 16) &0x000000ff;
	header[25] = (height >> 24) &0x000000ff;
		
	/* �½�һ���ļ� */
	bmpres = f_open( &bmpfsrc , (char*)filename, FA_CREATE_ALWAYS | FA_WRITE );
	
	/* �½��ļ�֮��Ҫ�ȹر��ٴ򿪲���д�� */
	f_close(&bmpfsrc);
		
	bmpres = f_open( &bmpfsrc , (char*)filename,  FA_OPEN_EXISTING | FA_WRITE);

	if ( bmpres == FR_OK )
	{    
		/* ��Ԥ�ȶ���õ�bmpͷ����Ϣд���ļ����� */
		bmpres = f_write(&bmpfsrc, header,sizeof(unsigned char)*54, &mybw);		
			
		ucAlign = Width % 4;
		
		for(i=0; i<Height; i++)					
		{
			for(j=0; j<Width; j++)  
			{					
				read_data = LCD_ReadPoint(x + j, y+ Height-1-i);					
				
				r =  (unsigned char)(( ((unsigned short int )read_data) >>11)<<3);		  			//����8λ R
				g =  (unsigned char)(( ((unsigned short int )(read_data & 0x7ff)) >>5)<<2); 	//����8λ G
				b =  (unsigned char)(( ((unsigned short int )(read_data & 0x1f))<<3));       	//����8λ B

				bmpres = f_write(&bmpfsrc, &b,sizeof(unsigned char), &mybw);
				bmpres = f_write(&bmpfsrc, &g,sizeof(unsigned char), &mybw);
				bmpres = f_write(&bmpfsrc, &r,sizeof(unsigned char), &mybw);
			}
				
			if( ucAlign )				/* �������4�ֽڶ��� */
				bmpres = f_write ( & bmpfsrc, kk, sizeof(unsigned char) * ( ucAlign ), & mybw );

		}/* ������� */

		f_close(&bmpfsrc); 
		
		return 0;
		
	}	
	else/* ����ʧ�� */
		return -1;
}
















