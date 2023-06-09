/*
 * MUSART_Config.h
 *
 *  Created on: Jun 8, 2023
 *      Author: John
 */

#ifndef MUSART_CONFIG_H_
#define MUSART_CONFIG_H_

/****************************************************************************/
/*                     USART MODES :                                        */
/* 								   - USART1 , USART2 , USART6               */
/****************************************************************************/
#define USART_USED    USART1

/****************************************************************************/
/*                         USART LENGTH MODES : 8-BIT , 9-BIT               */
/****************************************************************************/
#define _8DATA_LENGTH_         0
#define _9DATA_LENGTH_         1
/****************************************************************************/
/*             USART STOP BIT MODES : 00 -> ONE_STOP , 10 -> TWO_STOP       */
/****************************************************************************/

#define USART1_ONE_STOP_BITS  00
#define USART1_TWO_STOP_BITS  10
#endif /* MUSART_CONFIG_H_ */
