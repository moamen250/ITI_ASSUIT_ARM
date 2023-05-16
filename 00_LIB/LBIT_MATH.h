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
 /*
  *      ADD | by : Mohamed Yehia  :
  *                        @Example  :  We can use it if we need group of pins  ( from  5  to 12  )  or  need all pins except ( from 5 to 12 ) like  ( 0bx1110 0000 0001 1111 )
  */
#define PUT_ONS(  _FROM_   ,   _TO_   )         ( (  u32  )( ( ( 2 << ( ( _TO_ ) - ( _FROM_ ) ) ) - 1 ) << ( _FROM_ ) ) )
#define PUT_ZEROS(  _FROM_  ,  _TO_ )           ( ~PUT_ONS(  _FROM_   ,   _TO_   )  )
/***********************************************************************************************************************************************/
/*                                                                                          The   End                                                                                                                       */
/***********************************************************************************************************************************************/
#endif
