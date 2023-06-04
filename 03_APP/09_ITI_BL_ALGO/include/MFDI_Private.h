/*
 * MFDI_Private.h
 *
 *  Created on: Jun 4, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MFDI_PRIVATE_H_
#define MFDI_PRIVATE_H_

/******************************************************************************/
/*              Object Like Macro For  Base Address Registers                 */
/******************************************************************************/

#define MFDI_BASE_ADDRESS  0x40023C00

/******************************************************************************/
/*                    GPIO Registers Definition by struct                     */
/******************************************************************************/
typedef struct
{
	volatile u32 ACR     ;
    volatile u32 KEYR    ;
    volatile u32 OPTKEYR ;
    volatile u32 SR      ;
    volatile u32 CR      ;
    volatile u32 OPTCR   ;

}MFDI_t;



#define MFDI        ((MFDI_t*)(MFDI_BASE_ADDRESS))


#endif /* MFDI_PRIVATE_H_ */
