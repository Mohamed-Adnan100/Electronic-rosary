/* 
 * File  :   MCAL_std_types.h
 * Author:   mohame_dadnan
 *
 * Created on July 21, 2023, 11:03 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/****** Includes section                     ******/
#include "std_libraries.h"
#include "compiler.h"

/****** Macro declarations section           ******/
#define STD_HIGH         0X01
#define STD_LOW          0X00 

#define STD_ON           0X01
#define STD_OFF          0X00

#define STD_ACTIVE       0X01
#define STD_IDEL         0X00

#define E_OK          (Std_ReturnType)0X01
#define E_NOT_OK      (Std_ReturnType)0X00

/****** Macro functions declarations section ******/

/****** Data types section                   ******/
typedef unsigned char  uint8   ;
typedef unsigned short uint16  ;
typedef unsigned int   uint32  ;
typedef signed char    suint8  ;
typedef signed short   suint16 ;
typedef signed int     suint32 ;

typedef uint8          Std_ReturnType ;

/****** functions section                    ******/

#endif	/* MCAL_STD_TYPES_H */

