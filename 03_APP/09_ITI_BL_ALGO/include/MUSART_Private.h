/*
 * MUSART_Private.h
 *
 *  Created on: Jun 4, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_

#define MUSART_BASE_ADDRESS     0x40011000

typedef struct
{

volatile u32 USART_SR;
volatile u32 USART_DR;
volatile u32 USART_BRR;
volatile u32 USART_CR1;
volatile u32 USART_CR2;
volatile u32 USART_CR3;
volatile u32 USART_GTPR

}MUSART_t;

#define MUSART                 ((MUSART_t*)(MUSART_BASE_ADDRESS))




#endif /* MUSART_PRIVATE_H_ */
