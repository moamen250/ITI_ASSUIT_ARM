/***************************************************************************/
/* Author       : John Makkar                                              */
/* Version      : V0.0.0                                                   */
/*  Date        :  8 Jun 2023                                              */
/*  Author      : John                                                     */
/*  Description : Driver Functions Prototypes                              */
/*  Features    :                                                          */
/***************************************************************************/

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

/***************************************************************************/
/*                        Functions Prototypes                             */
/***************************************************************************/
ES_t MUSART_voidInit(void);
ES_t MUSART_voidEnable(u8 Copy_u8Index);
ES_t MUSART_voidDisable(u8 Copy_u8Index);
ES_t MUSART_voidSendData(u8 Copy_u8Index , u8 *Copy_Pu8Data , u8 Copy_u8Lenght);
u8 MUSART_voidReceiveData(u8 Copy_u8Index);


#endif /* MUSART_INTERFACE_H_ */
