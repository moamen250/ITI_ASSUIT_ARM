/**************************************************************************/
/*Author            : Ahmed Reda Morsi                                    */
/*Version           : V1.0.0                                              */
/*Date              : 28 April 2023                                       */
/*Description       : LBIT_MATH.h                                         */
/**************************************************************************/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/**************************************************************************/
/*                    Macros funcitons for Bit operations                 */
/**************************************************************************/

#define SET_BIT(REG , BITNUM)     ((REG) |=  (1U<<(BITNUM)))
#define CLR_BIT(REG , BITNUM)     ((REG) &= ~(1U<<(BITNUM)))
#define TOG_BIT(REG , BITNUM)     ((REG) ^=  (1U<<(BITNUM)))
#define GET_BIT(REG , BITNUM)     ( ((REG) >>(BITNUM))&1U  ) 
#define SET_BITS(REG , VAL)       ((REG) |= (VAL))
#define CLR_BITS(REG , MSK)       ((REG) &= (MSK))
#define TOG_BITS(REG , MSK)       ((REG) ^= (MSK))
#define SET_ALL_BITS(REG)         ((REG) = (0xFFFFFFFF))
#define CLR_ALL_BITS(REG)         ((REG) = (0U) )
#define TOG_ALL_BITS(REG)         ((REG) = ~(REG))

#endif