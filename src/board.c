/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "board.h"

#include "led.h"
#include "uavtalk.h"
#include "osdproc.h"
#include "osdcore.h"
#include "osdmavlink.h"
#include "max7456.h"
#include "usart2.h"
#include "osdconfig.h"
#include "math3d.h"
#include "osdvar.h"

void vTaskHeartBeat(void *pvParameters);
void vTask10HZ(void *pvParameters);
void triggerVideo(void);
void triggerPanel(void);
void checkDefaultParam(void);

uint8_t video_switch=0;

xTaskHandle xTaskVCPHandle;

int32_t pwmPanelNormal = 0;

void board_init(void)
{
	GPIO_InitTypeDef  gpio;
	SystemCoreClockUpdate( );

    // turn on peripherals needed by all
    RCC_AHB1PeriphClockCmd(	RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
							RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD |
							RCC_AHB1Periph_DMA1  | RCC_AHB1Periph_DMA2  |
							RCC_AHB1Periph_BKPSRAM, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_TIM2 |
							RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 | RCC_APB1Periph_TIM5 |  RCC_APB1Periph_TIM12 |
                     RCC_APB1Periph_PWR, ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	RCC_LSEConfig(RCC_LSE_OFF);

	LEDInit(LED_BLUE);
	LEDInit(LED_GREEN);


    Build_Sin_Cos_Tables();
    
    uart4_init();
LEDToggle(LED_GREEN);
    //clear_all_params();
    //LoadParams();


}

void module_init(void)
{
	xTaskCreate( vTaskHeartBeat, (const char*)"Task Heartbeat",
		STACK_SIZE_MIN, NULL, THREAD_PRIO_LOW, NULL );

	xTaskCreate( vTask10HZ, (const char*)"Task 10HZ",
		STACK_SIZE_MIN, NULL, THREAD_PRIO_NORMAL, NULL );

//    xTaskCreate( vTaskOSD, (const char*)"Task OSD",
//        STACK_SIZE_MIN*2, NULL, THREAD_PRIO_HIGHEST, NULL );

//	xTaskCreate( vTaskVCP, (const char*)"Task VCP",
//        STACK_SIZE_MIN*2, NULL, THREAD_PRIO_NORMAL, &xTaskVCPHandle );


    xTaskCreate( MavlinkTask, (const char*)"Task Mavlink",
        STACK_SIZE_MIN*2, NULL, THREAD_PRIO_HIGH, NULL );



//	xTaskCreate( DJICanTask, (const char*)"DJI CAN",
//	STACK_SIZE_MIN, NULL, THREAD_PRIO_HIGH, NULL );
}

void vTaskHeartBeat(void *pvParameters)
{
	for(;;)
	{
//		LEDToggle(LED_GREEN);
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}

void vTask10HZ(void *pvParameters)
{
    enable_mav_request = 1;
    for(;;)
        {
            vTaskDelay( 100 / portTICK_RATE_MS );

            // calculate osd_curr_consumed_mah(simulation)
            osd_curr_consumed_mah += (osd_curr_A * 0.00027777778f);

            // calculate osd_total_trip_dist(simulation)
            if (osd_groundspeed > 1.0f) osd_total_trip_dist += (osd_groundspeed * 0.1f);   // jmmods > for calculation of trip , Groundspeed is better than airspeed


            //if no mavlink update for 2 secs, show waring and request mavlink rate again
            if(GetSystimeMS() > (lastMAVBeat + 2200))
            {
                heatbeat_start_time = 0;
                waitingMAVBeats = 1;
            }

            if(enable_mav_request == 1)
            {

                for(int n = 0; n < 6; n++){
                    LEDToggle(LED_GREEN);
                    request_mavlink_rates();//Three times to certify it will be readed
                    vTaskDelay(150/portTICK_RATE_MS);
                }
                enable_mav_request = 0;
                waitingMAVBeats = 0;
                lastMAVBeat = GetSystimeMS();

            }
            
//            if(enable_mission_count_request == 1)
//            {
//                request_mission_count();
//                enable_mission_count_request = 0;
//            }

//            if(enable_mission_item_request == 1)
//            {
//                request_mission_item(current_mission_item_req_index);
//            }

        }
}


uint32_t GetSystimeMS(void)
{
	return (uint32_t)TICKS2MS(xTaskGetTickCount());
}

float Rad2Deg(float x)
{
    return x * (180.0F / M_PI);
}

float Deg2Rad(float x)
{
    return x * (M_PI / 180.0F);
}

void Delay_us(u32 nus)
{
	u16 i=0;
	while(nus--)
	{
		i=12;
		while(i--);
	}
}

