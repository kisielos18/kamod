/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "defines.h"
#include "stm32_Hw.h"
#include "crc.h"
#include "debug.h"
#include "stdint.h"

static void test(void);


int main(void)
{
    char c = 0;
    int g = 0, b = 0, r = 0;

    stm32_Hw_Init();

    GREEN_OFF;
    RED_OFF;
    BLUE_OFF;

    TM_USART_Puts(USART2, ">");

	for(;;)
	{
	    c = TM_USART_Getc(USART2);
	    //TM_USART_Send(USART2, &c, 1);
	    dbg("%c", c);
	    switch(c)
	    {
	    case 'c':
	    {
	       test();
	        break;
	    }
	        case 'g':
	            if(g)
                {
	                GREEN_OFF;
	                g = 0;
                }
	            else
	            {
                    GREEN_ON;
                    g = 1;
	            }
	            break;
	        case 'r':
	            if(r)
                {
                    RED_OFF;
                    r = 0;
                }
                else
                {
                    RED_ON;
                    r = 1;
                }
            break;
	        case 'b':
                if(b)
                {
                    BLUE_OFF;
                    b = 0;
                }
                else
                {
                    BLUE_ON;
                    b = 1;
                }

	        break;

	    }
	    //GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
	    delay_ms(1);

	}
}
static unsigned int reverse(unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));
}

static void test(void)
{
    uint8_t conf = 0;
    char value[10];
    uint16_t crc;
    unsigned char send_buff[5] = {0, 0xA0, 0x02, 0, 0};
    unsigned char recive_buff[5] = {0,};
    crc = CRC16_Calc(send_buff, 3);
    dbg("0x%04X\r\n", crc);
    send_buff[4] = crc;
    send_buff[3] = crc>>8;

    dbg("\r\nstart\r\n");
    TM_I2C_WriteMultiNoRegister(I2C1, 0b10100110, send_buff, 5);

    GREEN_ON;

    TM_I2C_ReadMultiNoRegister(I2C1, 0b10100110, recive_buff, 4);

    GREEN_OFF;
    BLUE_ON;

    dbg("0x%02X 0x%02X 0x%02X 0x%02X\r\n", recive_buff[0],recive_buff[1], recive_buff[2],recive_buff[3]);
}
