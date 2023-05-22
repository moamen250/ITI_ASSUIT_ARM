/******************************************************************************/
/* Auther                : Peter Essam                                        */
/* Version               : V1.0.0                                             */
/* Date                  : 19 -5- 2023                                        */
/* Description           : Register Description                               */
/******************************************************************************/

/******************************************************************************/
/*              Guard of File with Call on time in .c                         */
/******************************************************************************/

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

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
/*              Object Like Macro For NVIC Base Address Registers              */
/******************************************************************************/

#define MNVIC_BASE_ADDRESS		(0xE000E100)

/******************************************************************************/
/*                             MGPIO   BIT- MASK                              */
/******************************************************************************/
#define  BITS_PER_INT                      240U

/******************************************************************************/
/*                         Macros of NVIC Register Map                         */
/******************************************************************************/

///*ISER start from 0xE000E100*/
//#define	NVIC_ISER0		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x000)))
//#define	NVIC_ISER1		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x004))
//
///*ICER start from 0xE000E180*/
//#define	NVIC_ICER0		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x080)))
//#define	NVIC_ICER1		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x084)))
//
///*ISPR start from 0xE000E200*/
//#define	NVIC_ISPR0		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x100)))
//#define	NVIC_ISPR1		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x104)))
//
///*ICPR start from 0xE000E280*/
//#define	NVIC_ICPR0		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x180)))
//#define	NVIC_ICPR1		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x184)))
//
///*IABR start from 0xE000300*/
//#define	NVIC_IABR0		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x200)))
//#define	NVIC_IABR1		(*((volatile u32*)(MNVIC_BASE_ADDRESS+0x204)))
//
///*IPR start from 0xE000E400*/
//#define	NVIC_IPR0  		 (*((volatile u32*)(MNVIC_BASE_ADDRESS+0x300)))
//#define NVIC_IPR1        (*((volatile u32*)(MNVIC_BASE_ADDRESS+0x304)))
//
//#define NVIC_STIR        (*((volatile u32*)(MNVIC_BASE_ADDRESS+0xE00)))


//-------------------------------------------------------------------------------

typedef struct
{
  u32 ISER[8] ;
  u32 RESERVED0[24];
  u32 ICER[8] ;
  u32 RESERVED1[24];
  u32 ISPR[8]      ;
  u32 RESERVED2[24];
  u32 ICPR[8]      ;
  u32 RESERVED3[24];
  u32 IABR[8] ;
  u32 RESERVED4[56];
  u8  IPR[240]     ;
  u32 RESERVED5[580];
  u32 STIR     ;
}NVIC_t ;


#define MNVIC             ( (volatile NVIC_t*)(MNVIC_BASE_ADDRESS) )

#define  MSCB_AIRCR       (*(volatile u32*)(0xE000ED0C))

#define  VECTKEY          0x05FA0000


/*********************************************************************************************/
/************************************************************************************/

#if(0)
#define  NVIC_ISER0_BASE_Address                      0xE000E100
#define  BASE_OFFSET                                             0x4
typedef enum
{
	ISER =0x0 ,
	ICER=0x180,
	ISPR=0x200,
	ICPR=0x280,
	IABR=0x300,
	IPR   =0x400,
	STIR  =0xE00
} NVIC_OFFSECTs_Reg_t ;
/*******************************************************YOU CAN USE ******************************************/
#define   NVIC_REG( _NVIC_OFFSECTs_Reg_t_  , _REG_NUMBER_ )         (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (_NVIC_OFFSECTs_Reg_t_) +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )
// AT NVIC_STIR  use   _REG_NUMBER_   = 0
/*******************************************************OR  CAN USE *******************************************/
#define   NVIC_ISER(  _REG_NUMBER_  )         (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (ISER) +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )
#define   NVIC_ICER(  _REG_NUMBER_  )         (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (ICER) +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )
#define   NVIC_ISPR(  _REG_NUMBER_  )         (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (ISPR) +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )
#define   NVIC_ICPR(  _REG_NUMBER_  )         (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (ICPR) +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )
#define   NVIC_IABR(  _REG_NUMBER_  )         (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (IABR) +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )
#define   NVIC_IPR(  _REG_NUMBER_  )            (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+( (IPR)   +( (_REG_NUMBER_)*(BASE_OFFSET) ) ) )) )

#define   NVIC_STIR                                          (  *( (volatile u32*)( (NVIC_ISER0_BASE_Address)+ (STIR)  ) ) )

#endif
#endif /* MNVIC_PRIVATE_H_ */















