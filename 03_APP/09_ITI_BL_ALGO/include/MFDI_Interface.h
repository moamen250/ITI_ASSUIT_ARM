/*
 * MFDI_Interface.h
 *
 *  Created on: Jun 4, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_


void MFDI_voidSectorErase(u8 copy_u8SectorNum) ;
void MFDI_voidFlashWrite(u32 copy_u32Address, u16* Copy_pu16Data, u8 Copy_u8Length) ;
void MFDI_voidAppErase(void) ;

#endif /* MFDI_INTERFACE_H_ */
