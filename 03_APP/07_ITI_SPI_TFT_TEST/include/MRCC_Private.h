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

#define MRCC_BASE_ADDRESS 0x40023800

/******************************************************************************/
/*                         Macros of RCC Register Map                         */
/******************************************************************************/

#define MRCC_CR                             (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_PLLCFGR                        (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x04)))
#define MRCC_CFGR                           (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x08)))
#define MRCC_CIR                            (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x0C)))
#define MRCC_AHB1RSTR                       (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x10)))
#define MRCC_AHB2RSTR                       (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x14)))
#define MRCC_APB1RSTR                       (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x20)))
#define MRCC_APB2RSTR                       (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x24)))
#define MRCC_AHB1ENR                        (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x30)))
#define MRCC_AHB2ENR                        (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x34)))
#define MRCC_APB1ENR                        (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x40)))
#define MRCC_APB2ENR                        (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x44)))
#define MRCC_AHB1LPENR                      (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x50)))
#define MRCC_AHB2LPENR                      (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x54)))
#define MRCC_APB1LPENR                      (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x60)))
#define MRCC_APB2LPENR                      (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x64)))
#define MRCC_BDCR                           (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x70)))
#define MRCC_CSR                            (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x74)))
#define MRCC_SSCGR                          (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x80)))
#define MRCC_PLLI2SCFGR                     (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x84)))
#define MRCC_DCKCFGR                        (*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x8C)))


/******************************************************************************/
/*                          Clock Source Options                              */
/******************************************************************************/

/*
 *     -CLOCK SOURCE Option:
 *            1) MRCC_HSI
 *            2) MRCC_HSE
 *            3) MRCC_PLL
 */

#define MRCC_HSI     0
#define MRCC_HSE     1
#define MRCC_PLL     2

/******************************************************************************/
/*                              Clock HSE Options                             */
/******************************************************************************/

/*
 *     -CLOCK SOURCE Option For HSE:
 *            1) MRCC_HSE_MECH
 *            2) MRCC_HSE_ELEC
 */


#define   MRCC_HSE_MECH     0
#define   MRCC_HSE_ELEC     1


/******************************************************************************/
/*                         Clock Source OF PLL Options                        */
/******************************************************************************/

/*
 *     -CLOCK SOURCE Option For PLL:
 *            1) MRCC_HSE_SRC
 *            2) MRCC_HSI_SRC
 */
#define    MRCC_HSE_SRC    0
#define    MRCC_HSI_SRC    1


#define    READY           1

#endif /* MRCC_PRIVATE_H_ */
