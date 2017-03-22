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
static char *buffer_isr;
static int dbg_initialized = 0;
static void (*dbg_redirect)(void *param, char *buf, int len);
static void *dbg_param;

static uint32_t timeout = 5000;

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
        if (dbg_redirect)
        {
            dbg_redirect(dbg_param, buffer, len);
        }
        else
        {
            TM_USART_Send(USARTn, (uint8_t *)buffer, len);

        }
#if 0
    }

    else
    {
        char           *str = buffer_isr;
        int             len = 0;
        va_list         args;
        char           *red = "\x1b[31m";
        char           *red_end = "\x1b[0m";

        if (!dbg_initialized)
        {
            return;
        }
          HAL_UART_Transmit(&UsartHandle, red, strlen(red), timeout);

        va_start(args, fmt);
        len = vsprintf(str, fmt, args);
        HAL_UART_Transmit(&UsartHandle, buffer_isr, len, timeout);
        HAL_UART_Transmit(&UsartHandle, red_end, strlen(red_end), timeout);
    }
#endif
}

void dbg_red(const char *fmt, ...)
{
    char           *str = buffer;
    int             len = 0;
    va_list         args;

    va_start(args, fmt);

    if (!dbg_initialized)
    {
        return;
    }
    strcpy(str,"\x1b[31m");
    len = strlen(str);
    len += vsnprintf(str + len, DEBUG_BUFFER_SIZE - 1, fmt, args);
    
    if (len > DEBUG_BUFFER_SIZE)
    {
        TM_USART_Send(USARTn, (uint8_t *)("UART buffer overflow\r\n"), strlen("UART buffer overflow\r\n"));

    }
    if (dbg_redirect)
    {
        dbg_redirect(dbg_param, buffer, len);
    }
    else
    {
        strcat(str,"\x1b[0m");
        len += strlen(str);
        TM_USART_Send(USARTn, (uint8_t *)buffer, len);
    }

}

void dbg_init(void)
{
    buffer = malloc(DEBUG_BUFFER_SIZE);
    buffer_isr = malloc(DEBUG_BUFFER_SIZE);

    dbg_initialized = 1;
}
