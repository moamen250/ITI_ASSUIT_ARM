/******************************************************************************/
/* Auther                : Ahmed Hammad                                       */
/* Version               : V1.0.0                                             */
/* Date                  : 28 Apri 2023                                       */
/* Description           : LSTD_TYPES.h                                       */
/******************************************************************************/


/******************************************************************************/
/*              Guard of File with Call on time in .c                         */
/******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*******************************************************************************/
/*                             Renaming The data types                         */
/*******************************************************************************/


typedef unsigned char                  u8      ;
typedef unsigned  short int            u16     ;
typedef unsigned long int              u32     ;
typedef signed char                    s8      ;
typedef signed  short int              s16     ;
typedef signed int                     s32     ;
typedef float                          f32     ;
typedef double                         f64     ;


/*******************************************************************************/
/*                                   BOOLEAN Values                            */
/*******************************************************************************/

#ifndef TRUE 
#define TRUE       (1U)
#endif

#ifndef FALSE 
#define FALSE      (0U)
#endif

/*******************************************************************************/
/*                                      NULL   Define                          */
/*******************************************************************************/

#ifndef NULL 
#define NULL      (void*)0
#endif

#endif

