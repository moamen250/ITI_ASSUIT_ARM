/**************************************************************************/
/*Author            : Mariam Ayman                                        */
/*Version           : V1.0.0                                              */
/*Date              : 13 MAY 2023                                         */
/*Description       : H7SEG_Program.c                                     */
/*Features          :                                                     */
/*        - MGPIO_errSetPinMode()                                         */
/*        - MGPIO_errSetPinData()                                         */
/**************************************************************************/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/

#ifndef H7SEG_CONFIG_H_
#define H7SEG_CONFIG_H_

/**************************************************************************/
/*  define the 7Segment Type:                                             */
/*                           1- COM_CATHODE                               */
/*                           2- COM_ANODE                                 */
/**************************************************************************/
#define    H7SEG_TYPE      COM_CATHODE

/**************************************************************************/
/*    define the port connected to the 7-segment display                  */
/**************************************************************************/
#define H7SEG_PORT MGPIO_PORTA

/**************************************************************************/
/*    define the pins connected to the 7-segment display                  */
/**************************************************************************/
#define H7SEG_PIN_A MGPIO_PIN0
#define H7SEG_PIN_B MGPIO_PIN1
#define H7SEG_PIN_C MGPIO_PIN2
#define H7SEG_PIN_D MGPIO_PIN3
#define H7SEG_PIN_E MGPIO_PIN4
#define H7SEG_PIN_F MGPIO_PIN5
#define H7SEG_PIN_G MGPIO_PIN6

#endif /* H7SEG_CONFIG_H_ */
