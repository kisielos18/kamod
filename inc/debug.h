/*
 * debug.h
 *
 *  Created on: Oct 23, 2011
 *      Author: ja
 */

#include "stm32f4xx_usart.h"

#ifndef DEBUG_H_
#define DEBUG_H_

#define USARTn                          USART2
/* Size of Transmission buffer */
#define TXBUFFERSIZE                      (COUNTOF(aTxBuffer) - 1)
/* Size of Reception buffer */
#define RXBUFFERSIZE                      TXBUFFERSIZE

/* Initialize debug module */
void dbg_init(void);

/* print debug message - can be called from task context only */
void dbg(const char *fmt, ...);

#endif /* DEBUG_H_ */
