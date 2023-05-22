/**************************************************************************/
/* Auther                : Peter Essam                                    */
/* Version               : V1.0.0                                         */
/* Date                  : 19-5-2023                                      */
/* Description           : MNVIC_                              */
/* Features              :                                                */
/*           1- MNVIC_errInitSoftwareSystemPriority()                     */
/*           2- MNVIC_errEnablePerInterrupt()                             */
/*           3- MNVIC_errDisablePerInterrupt()                            */
/*           4- MNVIC_errSetPendingInterrupt()                            */
/*           5- MNVIC_errClearPeningInterrupt()                           */
/*           6- MNVIC_errIsInterruptActive()                              */
/*           7- MNVIC_errSetInterruptPriority()                           */
/**************************************************************************/

/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "MNVIC_Private.h"
#include "MNVIC_Config.h"
#include "MNVIC_Interface.h"

/**************************************************************************/
/*                 MNVIC Functions implementation                         */
/**************************************************************************/


static MNVIC_SysPriority_t GLB_uddtSysPriority ;
ES_t MNVIC_errInitSoftwareSystemPriority(MNVIC_SysPriority_t Copy_uddtPriorityOption)
{
	GLB_uddtSysPriority  = Copy_uddtPriorityOption ;
	//TODO   -> Mariam
}

// Error state -> Yahya
ES_t MNVIC_errEnablePerInterrupt(u8 Copy_u8IntIndex)  //32
{
	MNVIC->ISER[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
}
ES_t MNVIC_errDisablePerInterrupt(u8 Copy_u8IntIndex)
{
	MNVIC->ICER[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
}
ES_t MNVIC_errSetPendingInterrupt(u8 Copy_u8IntIndex)
{
	MNVIC->ISPR[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
}
ES_t MNVIC_errClearPeningInterrupt(u8 Copy_u8IntIndex)
{
	MNVIC->ICPR[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
}
ES_t MNVIC_errIsInterruptActive(u8 Copy_u8IntIndex , u8* Copy_pu8ActiveStatus)
{
	//TODO   --> Ahmed Reda
}
  
  /*****************************************************************************************************************************************/
  /*                                    07- MNVIC_errSetInterruptPriority                                                                  */
  /*                                    Wtitten By : MINA NABIL BADEE                                                                      */
  /*****************************************************************************************************************************************/
  /* 1- Function Description                                                                                                               */
  /*                        @brief:set the interrupt priority by setting prephiral index from 0 - 239                                      */
  /*                       and num of group from 0 - 15 and num of subgroup from 0 -15                                                     */
  /* 2- Function Input                                                                                                                     */                                        */
  /*               @param : Copy_u8IntIndex prephiral index                                                                                */                     
  /*               @param : Copy_uddtGPriority  number groups          @ref : MNVIC_GPriority_t                                            */                                             */
  /*               @param :Copy_uddtSubGPriority number of subgroups   @ref :    MNVIC_SUBPriority_t                                       */
  /* 3- Function Return                                                                                                                    */                        */
  /*               @return Error status of the function                                                                                    */                       */
  /*                              (E_OK) : The function done successfully                                                                  */
  /*                              (ES_OUT_OF_RANGE_PRE_INT) : The user enter invalid prephiral index < 0 and >239                          */
  /*                              (MNVIC_INVALID_Priority)  : The user enter invalid priority < MNVIC_G16_S0 = 3 and > MNVIC_G0_S16=7      */                                         */
  /*                              (MNVIC_GROUP_INVALID) : The user enter number of group > 15                                              */
  /*                              (MNVIC_SUBGROUP_INVALID) : The user enter number of group > 15                                           */
  /*****************************************************************************************************************************************/

ES_t MNVIC_errSetInterruptPriority(u8 Copy_u8IntIndex ,MNVIC_GPriority_t Copy_uddtGPriority ,MNVIC_SUBPriority_t  Copy_uddtSubGPriority )

	
	ES_t LOC_uddtState = ES_OK;
	if(GLB_uddtSysPriority < 3 || GLB_uddtSysPriority > MNVIC_G0_S16){LOC_uddtState=MNVIC_INVALID_Priority;}
		

	else
	{
	    if(Copy_u8IntIndex < 0  || Copy_u8IntIndex > 239){LOC_uddtState=ES_OUT_OF_RANGE_PRE_INT;}
		else {
		MNVIC->IPR[Copy_u8IntIndex]=0;
		switch(GLB_uddtSysPriority){
			//in case of GLB_uddtSysPriority =MNVIC_G16_S0 -->   G=16   SG=0
			case MNVIC_G16_S0:
			
			if(Copy_uddtGPriority < 0 || Copy_uddtGPriority > 15) {LOC_uddtState=MNVIC_GROUP_INVALID;}
			else{ MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<2) | (Copy_uddtGPriority))<<4;}
			break;
			//in case of GLB_uddtSysPriority =MNVIC_G8_S2 -->   G=8   SG=2
			case MNVIC_G8_S2:
			
			if((Copy_uddtGPriority < 0) || (Copy_uddtGPriority > 7)){LOC_uddtState=MNVIC_GROUP_INVALID;}
            else if((Copy_uddtSubGPriority < 0) || (Copy_uddtSubGPriority > 1)){LOC_uddtState=MNVIC_SUBGROUP_INVALID;}
			else{MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<2) | (Copy_uddtGPriority))<<4;}
			break;
			
			//in case of GLB_uddtSysPriority =MNVIC_G4_S4 -->   G=4   SG=4

			case MNVIC_G4_S4:
			
			if((Copy_uddtGPriority < 0) || (Copy_uddtGPriority > 3)){LOC_uddtState=MNVIC_GROUP_INVALID;}
		    else if((Copy_uddtSubGPriority < 0) || (Copy_uddtSubGPriority > 1)){LOC_uddtState=MNVIC_SUBGROUP_INVALID;}
			else {MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<2) | (Copy_uddtGPriority))<<4;}
			break;
			
			//in case of GLB_uddtSysPriority =MNVIC_G2_S8 -->   G=2   SG=8
			case MNVIC_G2_S8:
			
			if((Copy_uddtGPriority < 0) || (Copy_uddtGPriority > 1)){LOC_uddtState=MNVIC_GROUP_INVALID;}
			else if((Copy_uddtSubGPriority < 0) || (Copy_uddtSubGPriority > 7)){LOC_uddtState=MNVIC_SUBGROUP_INVALID;}
			else {MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<2) | (Copy_uddtGPriority))<<4;}
			break;
			//in case of GLB_uddtSysPriority =MNVIC_G0_S16 -->   G=0   SG=16
			case MNVIC_G0_S16:
			if(Copy_uddtSubGPriority < 0 || Copy_uddtSubGPriority > 15) {LOC_uddtState=MNVIC_SUBGROUP_INVALID;}
			else {MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<2) | (Copy_uddtGPriority))<<4;}
			break;
			
		}
		
		}
	}
	
	return LOC_uddtState;
}
