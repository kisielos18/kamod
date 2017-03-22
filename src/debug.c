/*
 * debug.c
 *
 *  Created on: Oct 23, 2011
 *      Author: ja
 */
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include "tm_stm32f4_usart.h"

#define DEBUG_BUFFER_SIZE      1024

static char *buffer;
static int dbg_initialized = 0;

void dbg(const char *fmt, ...)
{
        char           *str = buffer;
        int             len = 0;
        va_list         args;

        va_start(args, fmt);

        if (!dbg_initialized)
        {
            return;
        }

        len = vsnprintf(str, DEBUG_BUFFER_SIZE - 1, fmt, args);
        if (len > DEBUG_BUFFER_SIZE)
        {
            TM_USART_Send(USARTn, (uint8_t*)"UART buffer overflow\r\n", strlen("UART buffer overflow\r\n"));

        }
        else
        {
            TM_USART_Send(USARTn, (uint8_t *)buffer, len);

        }
}

void dbg_init(void)
{
    buffer = malloc(DEBUG_BUFFER_SIZE);

    dbg_initialized = 1;
}
