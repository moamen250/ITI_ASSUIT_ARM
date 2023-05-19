/**************************************************************************/
/* Auther                : Peter Essam                                    */
/* Version               : V1.0.0                                         */
/* Date                  : 19-5-2023                                      */
/* Description           : MNVIC_Interface.h                              */
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
/*                    Guard for calling one time in .c files              */
/**************************************************************************/


#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_




typedef enum
{
	MNVIC_G16_S0 = 3 ,
	MNVIC_G8_S2      ,
	MNVIC_G4_S4      ,
	MNVIC_G2_S8      ,
	MNVIC_G0_S16     ,
	MNVIC_INVALID_Priority
}MNVIC_SysPriority_t ;

typedef enum
{
	MNVIC_GROUP_PRI0 = 0 ,
	MNVIC_GROUP_PRI1     ,
	MNVIC_GROUP_PRI2     ,
	MNVIC_GROUP_PRI3     ,
	MNVIC_GROUP_PRI4     ,
	MNVIC_GROUP_PRI5     ,
	MNVIC_GROUP_PRI6     ,
	MNVIC_GROUP_PRI7     ,
	MNVIC_GROUP_PRI8     ,
	MNVIC_GROUP_PRI9     ,
	MNVIC_GROUP_PRI10     ,
	MNVIC_GROUP_PRI11     ,
	MNVIC_GROUP_PRI12     ,
	MNVIC_GROUP_PRI13     ,
	MNVIC_GROUP_PRI14     ,
	MNVIC_GROUP_PRI15     ,
    MNVIC_GROUP_INVALID
}MNVIC_GPriority_t ;


typedef enum
{
	MNVIC_SUBGROUP_PRI0 = 0 ,
	MNVIC_SUBGROUP_PRI1     ,
	MNVIC_SUBGROUP_PRI2     ,
	MNVIC_SUBGROUP_PRI3     ,
	MNVIC_SUBGROUP_PRI4     ,
	MNVIC_SUBGROUP_PRI5     ,
	MNVIC_SUBGROUP_PRI6     ,
	MNVIC_SUBGROUP_PRI7     ,
	MNVIC_SUBGROUP_PRI8     ,
	MNVIC_SUBGROUP_PRI9     ,
	MNVIC_SUBGROUP_PRI10     ,
	MNVIC_SUBGROUP_PRI11     ,
	MNVIC_SUBGROUP_PRI12     ,
	MNVIC_SUBGROUP_PRI13     ,
	MNVIC_SUBGROUP_PRI14     ,
	MNVIC_SUBGROUP_PRI15     ,
    MNVIC_SUBGROUP_INVALID
}MNVIC_SUBPriority_t ;
/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/

ES_t MNVIC_errInitSoftwareSystemPriority(MNVIC_SysPriority_t Copy_uddtPriorityOption)           ;
ES_t MNVIC_errEnablePerInterrupt(u8 Copy_u8IntIndex)                                            ;
ES_t MNVIC_errDisablePerInterrupt(u8 Copy_u8IntIndex)                                           ;
ES_t MNVIC_errSetPendingInterrupt(u8 Copy_u8IntIndex)                                           ;
ES_t MNVIC_errClearPeningInterrupt(u8 Copy_u8IntIndex)                                          ;
ES_t MNVIC_errIsInterruptActive(u8 Copy_u8IntIndex , u8* Copy_pu8ActiveStatus)                  ;
ES_t MNVIC_errSetInterruptPriority(u8 Copy_u8IntIndex ,MNVIC_GPriority_t Copy_uddtGPriority ,MNVIC_SUBPriority_t  Copy_uddtSubGPriority )                 ;


#endif /* MNVIC_INTERFACE_H_ */
