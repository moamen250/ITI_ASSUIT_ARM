/***********************************************************************************************************/
/* Author :                           Mohamed Yehia El-Greatly                                             */
/* Description :                          HCLCD_Private.h                                                  */
/***********************************************************************************************************/
/* Version :V1.0.0                                                                                         */
/* Date :     13 May 2023                                                                                  */
/***********************************************************************************************************/
/*#########################################################################################################*/
/***********************************************************************************************************/
/*                          Guard of File with Call on time in .c                                          */
/***********************************************************************************************************/
#ifndef HAL_LCD_LCD_PRV_H_
#define HAL_LCD_LCD_PRV_H_
/***********************************************************************************************************/
/*                          HCLCD PreBuild Configuration Options                                           */
/***********************************************************************************************************/
#define  _8_BIT_MODE_                  0
#define  _4_BIT_MODE_                  1

#define  _ONE_PORT_                    0
#define  _TWO_PORT_                    1
/***********************************************************************************************************/
/*                               Renaming The data types                                                   */
/***********************************************************************************************************/

typedef  const  u8                HCLCD_Char ;
typedef  const  u8                HCLCD_Command ;
typedef  const u8*                HCLCD_String;
typedef const u8*                 HCLCD_SpecialCharArr;
typedef  s32                      HCLCD_SignedNumber;

/***********************************************************************************************************/
/*                    Object Like Macro Section  "From LCD DATASHEET "                                     */
/***********************************************************************************************************/
#define   DATA_PINS_OUTPUT            0xFF
/***********************************************************************************************************/
#define   RW_WRITE_RS_COMMAND          0U
#define   RW_READ_RS_COMMAND           2U
#define   RW_WRITE_RS_DATA             1U
/***********************************************************************************************************/
#define   RW_WRITE               MGPIO_PIN_LOW
#define   RW_READ                MGPIO_PIN_HIGH
/***********************************************************************************************************/
#define  EN_LOW                  MGPIO_PIN_LOW
#define  EN_HIGH                 MGPIO_PIN_HIGH
/***********************************************************************************************************/
#define  Size_of_Int                   10
/***********************************************************************************************************/
#define HLCD_FUNCSET_CMD              0x38
#define HLCD_4BITM_CMD                0x02
#define HLCD_FUNCSET_CMD              0x28
#define HLCD_DOC_CMD                  0x0C
#define HLCD_CLR_CMD                  0x01
#define HLCD_EMS_CMD                  0x06
#define HLCD_DDRAM__First_CMD         0x80
#define HLCD_DDRAM__Sec_CMD           0xC0
/***********************************************************************************************************/
/*                                            The   End                                                    */
/***********************************************************************************************************/
#endif /* HAL_LCD_LCD_PRV_H_ */
/*#########################################################################################################*/