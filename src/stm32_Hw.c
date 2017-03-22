/*
 * stm32_Hw.c
 *
 *  Created on: 28 cze 2016
 *      Author: kuba
 */
#include "stm32_Hw.h"
#include "defines.h"

static void GPIO_init(void)
{

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB, ENABLE);
    //Initialize struct
    GPIO_InitTypeDef GPIO_InitDef;

    memset(&GPIO_InitDef, 0x0, sizeof(GPIO_InitDef));

    GPIO_InitDef.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_10;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOA, &GPIO_InitDef);

    GPIO_InitDef.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_Init(GPIOB, &GPIO_InitDef);
}

void stm32_Hw_Init(void)
{
    SysTick_Config(SystemCoreClock/1000);
    GPIO_init();
    TM_USART_Init(USART2, TM_USART_PinsPack_1, 115200);
    TM_I2C_Init(I2C1,  TM_I2C_PinsPack_2, 50000);
    dbg_init();

}
