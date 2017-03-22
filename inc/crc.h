/*
 * crc.h
 *
 *  Created on: 30 cze 2016
 *      Author: kuba
 */

#ifndef CRC_H_
#define CRC_H_

#define CRC_OK      0
#define CRC_FAIL   -1

#define CRC_CHECK   2
#define CRC_CALC    3

uint16_t CRC16_Calc(uint8_t *Buffer, uint16_t ui_length);


#endif /* CRC_H_ */
