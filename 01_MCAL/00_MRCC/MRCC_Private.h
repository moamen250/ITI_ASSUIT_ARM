/******************************************************************************/
/* Auther                : Ahmed Hammad                                       */
/* Version               : V1.0.0                                             */
/* Date                  : 5 May 2023                                         */
/* Description           : MRCC_Private.h                                     */
/* Features              : Register Definitions                               */
/******************************************************************************/


/******************************************************************************/
/*              Guard of File with Call on time in .c                         */
/******************************************************************************/

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_


/******************************************************************************/
/*                              Register Definitions                          */
/*----------------------------------------------------------------------------*/
/*    - Developer can't edit in it                                            */
/*    - Design :                                                              */
/*                         -   #define        : YES                           */
/*                         -   Struct         : NO                            */
/*                         -   Union          : NO                            */
/******************************************************************************/


/******************************************************************************/
/*              Object Like Macro For RCC Base Address Registers              */
/******************************************************************************/

#define MRCC_BASE_ADDRESS            0x40023800

/******************************************************************************/
/*                         Macros of RCC Register Map                         */
/******************************************************************************/


#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_PLLCFRG           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x04)))
#define MRCC_CFGR              (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x08)))
#define MRCC_CIR               (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x0C)))
#define MRCC_AHB1RSTR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x10)))
#define MRCC_AHB2RSTR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x14)))
#define MRCC_APB1RSTR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x20)))
#define MRCC_APB2RSTR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_AHB1ENR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_CR                (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
















#endif /* MRCC_PRIVATE_H_ */
