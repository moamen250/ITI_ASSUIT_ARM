/*
 * MSPI_Interface.h
 *
 *  Created on: May 28, 2023
 *      Author: Ahmed Khaled Hammad
 */




void MSPI_voidInit(void) ;

u8 MSPI_u8SendReceive(u8 Copy_u8Data) ;

void MSPI1_voidSetCallBack(void(*Fptr)(void)) ;
