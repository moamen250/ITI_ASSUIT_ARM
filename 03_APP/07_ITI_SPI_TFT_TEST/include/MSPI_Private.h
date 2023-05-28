/*
 * MSPI_Private.h
 *
 *  Created on: May 28, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


#define MSPI1_BASE_ADDRESS           0x40013000

typedef struct
{
	volatile u32 CR1;
	volatile u32 RESERVED;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_Reg_t;



#define   MSPI1         ((SPI_Reg_t*)(MSPI1_BASE_ADDRESS))



#endif /* MSPI_PRIVATE_H_ */
