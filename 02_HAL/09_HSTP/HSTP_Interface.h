
/**************************************************************************/
/*Author            : Amr Wahba                                           */
/*Version           : V1.0.0                                              */
/*Date              : 26 MAY 2023                                         */
/*Description       :HSTP_Interface.h                                     */
/*Features          :                                                     */
/*         - void HSTP_voidInit(void)                                     */
/*         -void HSTP_voidSendData(u8 ptr_u8Data)                         */
/*         -void HSTP_void_LedMatrix(u8 *ptr_u8Data)                      */
/*                                                                        */
/*                                                                        */
/**************************************************************************/


/*************************************************************************************************************/
/*                                  Guard for calling one time in .c files                                   */
/*************************************************************************************************************/
#ifndef HSTP_INTERFACE_H_
#define HSTP_INTERFACE_H_




/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
void HSTP_voidInit(void);
void HSTP_voidSendData(u8 ptr_u8Data);
void HSTP_void_LedMatrix(u8 *ptr_u8Data);

#endif /* HSTP_INTERFACE_H_ */
