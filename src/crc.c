/*
 * crc.c
 *
 *  Created on: 30 cze 2016
 *      Author: kuba
 */
#include "stdint.h"
#include "crc.h"

#define  POLYNOMIAL 0x8408//  x^16 + x^12 + x^5 + 1
#define  PRESET_VALUE 0xFFFF
#define  CHECK_VALUE 0xF0B8

uint16_t CRC16_Calc(uint8_t *Buffer, uint16_t ui_length)
{
    unsigned int  current_crc_value;
    //unsigned char array_of_databytes[NUMBER_OF_BYTES + 2] = {1, 2, 3, 4, 0x91,0x39};
    int           number_of_databytes = 0;
    int           i, j;

   // calculate_or_check_crc = CHECK_CRC;// This could be an other example
    number_of_databytes = ui_length;

    current_crc_value = PRESET_VALUE;
     for (i = 0; i < number_of_databytes; i++)
     {
         current_crc_value = current_crc_value ^ ((unsigned int)Buffer[i]);
         for (j = 0; j < 8; j++)
         {
             if (current_crc_value & 0x0001)
             {
                 current_crc_value = (current_crc_value >> 1) ^ POLYNOMIAL;
             }
             else
             {
                 current_crc_value = (current_crc_value >> 1);
             }
         }
     }
     current_crc_value = ~current_crc_value;
    return current_crc_value;
}
