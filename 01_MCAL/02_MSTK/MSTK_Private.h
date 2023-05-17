/*
 * MSTK_Private.h
 *
 *  Created on: May 12, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_


#define  MSTK_BASE_ADDRESS   0xE000E010

#define MSTK_RESOLUTION           16777216(UL)

typedef struct
{
 volatile u32 CTRL ;
 volatile u32 LOAD ;
 volatile u32 VAL ;
 volatile u32 CALIB ;
}MSTK_t ;



#define MSTK          ((MSTK_t*)(MSTK_BASE_ADDRESS))


#endif /* MSTK_PRIVATE_H_ */
