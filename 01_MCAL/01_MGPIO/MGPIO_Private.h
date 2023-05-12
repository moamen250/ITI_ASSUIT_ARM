/******************************************************************************/
/* Auther                : Peter and Ghada                                    */
/* Version               : V1.0.0                                             */
/* Date                  : 6 May 2023                                         */
/* Description           : MGPIO_Program.c                                    */
/******************************************************************************/


/******************************************************************************/
/*                              Register Definitions                          */
/*----------------------------------------------------------------------------*/
/*    - Developer can't edit in it                                            */
/*    - Design :                                                              */
/*                         -   #define        : YES                           */
/*                         -   Struct         : YES                           */
/*                         -   Union          : NO                            */
/******************************************************************************/


/******************************************************************************/
/*              Guard of File with Call on time in .c                         */
/******************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/******************************************************************************/
/*              Object Like Macro For RCC Base Address Registers              */
/******************************************************************************/

#define GPIOA_BASE_ADDRESS	0X40020000
#define GPIOB_BASE_ADDRESS	0X40020400
#define GPIOC_BASE_ADDRESS	0X40020800
#define GPIOD_BASE_ADDRESS  0x40020C00   
#define GPIOE_BASE_ADDRESS	0x40021000   
#define GPIOH_BASE_ADDRESS  0x40021C00   


/******************************************************************************/
/*                    GPIO Registers Definition by struct                     */
/******************************************************************************/

typedef struct
{
	volatile u32 MODER     ;
    volatile u32 OTYPER    ;
    volatile u32 OSPEEDR   ;
    volatile u32 PUPDR     ;
    volatile u32 IDR       ;
    volatile u32 ODR       ;
	volatile u32 BSRR      ;
    volatile u32 LCKR      ;
	volatile u32 AFRL      ;
	volatile u32 AFRH      ;
}MGPIOx_t;


/******************************************************************************/
/*                          GPIOA Registers pointer                           */
/******************************************************************************/

#define MGPIOA                 ((MGPIOx_t*)(GPIOA_BASE_ADDRESS))

/******************************************************************************/
/*                          GPIOB Registers pointer                           */
/******************************************************************************/

#define MGPIOB                 ((MGPIOx_t*)(GPIOB_BASE_ADDRESS))

/******************************************************************************/
/*                          GPIOA Registers pointer                           */
/******************************************************************************/

#define MGPIOC                 ((MGPIOx_t*)(GPIOC_BASE_ADDRESS))




#define  BITS_MODE_MASK      3U
/******************************************************************************/
/*                             THE END OF DIFINITION                          */
/******************************************************************************/

/*PORTA Regs. */

#define GPIOA_MODER            (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x00)))	/*GPIO port mode register,               Address offset: 0x00      */
#define GPIOA_OTYPER           (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x04)))   /*GPIO port output type register,        Address offset: 0x04      */
#define GPIOA_OSPEEDR          (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x08)))   /*GPIO port output speed register,       Address offset: 0x08      */
#define GPIOA_PUPDR            (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x0C)))   /*GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
#define GPIOA_IDR              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x10)))   /*GPIO port input data register,         Address offset: 0x10      */
#define GPIOA_ODR              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x14)))   /*GPIO port output data register,        Address offset: 0x14      */
#define GPIOA_BSRR             (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x18)))   /*GPIO port bit set/reset register,      Address offset: 0x18      */
#define GPIOA_LCKR             (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x1C)))   /*GPIO port configuration lock register, Address offset: 0x1C      */

/*PORTB Regs. */

#define GPIOB_MODER            (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x00)))	/*GPIO port mode register,               Address offset: 0x00      */
#define GPIOB_OTYPER           (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x04)))   /*GPIO port output type register,        Address offset: 0x04      */
#define GPIOB_OSPEEDR          (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x08)))   /*GPIO port output speed register,       Address offset: 0x08      */
#define GPIOB_PUPDR            (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x0C)))   /*GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
#define GPIOB_IDR              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x10)))   /*GPIO port input data register,         Address offset: 0x10      */
#define GPIOB_ODR              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x14)))   /*GPIO port output data register,        Address offset: 0x14      */
#define GPIOB_BSRR             (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x18)))   /*GPIO port bit set/reset register,      Address offset: 0x18      */
#define GPIOB_LCKR             (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x1C)))   /*GPIO port configuration lock register, Address offset: 0x1C      */

/*PORTC Regs. */

#define GPIOC_MODER            (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x00)))	/*GPIO port mode registe ,               Address offset: 0x00      */
#define GPIOC_OTYPER           (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x04)))   /*GPIO port output type register,        Address offset: 0x04      */
#define GPIOC_OSPEEDR          (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x08)))   /* GPIO port output speed register,       Address offset: 0x08      */
#define GPIOC_PUPDR            (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x0C)))   /*GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
#define GPIOC_IDR              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x10)))   /* GPIO port input data register,         Address offset: 0x10      */
#define GPIOC_ODR              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x14)))   /*GPIO port output data register,        Address offset: 0x14      */
#define GPIOC_BSRR             (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x18)))   /*GPIO port bit set/reset register,      Address offset: 0x18      */
#define GPIOC_LCKR             (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x1C)))   /*GPIO port configuration lock register, Address offset: 0x1C      */


/*PORTD Regs. */
#define GPIOD_MODER            (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x00)))	/*GPIO port mode register,               Address offset: 0x00      */
#define GPIOD_OTYPER           (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x04)))   /*GPIO port output type register,        Address offset: 0x04      */
#define GPIOD_OSPEEDR          (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x08)))   /*GPIO port output speed register,       Address offset: 0x08      */
#define GPIOD_PUPDR            (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x0C)))   /*GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
#define GPIOD_IDR              (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x10)))   /* GPIO port input data register,         Address offset: 0x10      */
#define GPIOD_ODR              (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x14)))   /* GPIO port output data register,        Address offset: 0x14      */
#define GPIOD_BSRR             (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x18)))   /*GPIO port bit set/reset register,      Address offset: 0x18      */
#define GPIOD_LCKR             (*((volatile u32 *)(GPIOD_BASE_ADDRESS+0x1C)))   /* GPIO port configuration lock register, Address offset: 0x1C      */




/*PORTE Regs. */
#define GPIOE_MODER            (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x00)))	/* GPIO port mode register,               Address offset: 0x00      */
#define GPIOE_OTYPER           (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x04)))   /* GPIO port output type register,        Address offset: 0x04      */
#define GPIOE_OSPEEDR          (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x08)))   /* GPIO port output speed register,       Address offset: 0x08      */
#define GPIOE_PUPDR            (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x0C)))   /* GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
#define GPIOE_IDR              (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x10)))   /* GPIO port input data register,         Address offset: 0x10      */
#define GPIOE_ODR              (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x14)))   /* GPIO port output data register,        Address offset: 0x14      */
#define GPIOE_BSRR             (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x18)))   /* GPIO port bit set/reset register,      Address offset: 0x18      */
#define GPIOE_LCKR             (*((volatile u32 *)(GPIOE_BASE_ADDRESS+0x1C)))   /* GPIO port configuration lock register, Address offset: 0x1C      */





/*PORTH Regs. */
#define GPIOH_MODER            (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x00)))	/* GPIO port mode register,               Address offset: 0x00      */
#define GPIOH_OTYPER           (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x04)))   /* GPIO port output type register,        Address offset: 0x04      */
#define GPIOH_OSPEEDR          (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x08)))   /* GPIO port output speed register,       Address offset: 0x08      */
#define GPIOH_PUPDR            (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x0C)))   /* GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
#define GPIOH_IDR              (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x10)))   /* GPIO port input data register,         Address offset: 0x10      */
#define GPIOH_ODR              (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x14)))   /* GPIO port output data register,        Address offset: 0x14      */
#define GPIOH_BSRR             (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x18)))   /* GPIO port bit set/reset register,      Address offset: 0x18      */
#define GPIOH_LCKR             (*((volatile u32 *)(GPIOH_BASE_ADDRESS+0x1C)))   /* GPIO port configuration lock register, Address offset: 0x1C      */



#endif
