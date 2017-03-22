/*
 * defines.h
 *
 *  Created on: 28 cze 2016
 *      Author: kuba
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_it.h"
#include "tm_stm32f4_usart.h"
#include "stm32f4xx_i2c.h"
#include "stm32_Hw.h"
#include "tm_stm32f4_i2c.h"

/* I2C1 settings, change them in defines.h project file */
#define TM_I2C1_ACKNOWLEDGED_ADDRESS    I2C_AcknowledgedAddress_7bit
#define TM_I2C1_MODE                    I2C_Mode_I2C
#define TM_I2C1_OWN_ADDRESS             0x00
#define TM_I2C1_ACK                     I2C_Ack_Disable
#define TM_I2C1_DUTY_CYCLE              I2C_DutyCycle_2

#define SLAVE_ADDRESS 0x3D // the slave address (example)

#define GREEN_ON GPIO_SetBits(GPIOB, GPIO_Pin_5)
#define GREEN_OFF GPIO_ResetBits(GPIOB, GPIO_Pin_5)

#define RED_ON GPIO_SetBits(GPIOB, GPIO_Pin_4)
#define RED_OFF GPIO_ResetBits(GPIOB, GPIO_Pin_4)

#define BLUE_ON GPIO_SetBits(GPIOA, GPIO_Pin_10)
#define BLUE_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_10)


#endif /* DEFINES_H_ */
