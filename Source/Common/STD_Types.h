/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *			File	:	STD_TYPES.h
			Author	:	Michael Barakat
 *
 *  Description:  Contains basic standard types
 *  
 *********************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#define CLR_PTR       ((void *)0)
#define Clear					  0

typedef enum{
	Pending,
	Refused
}Std_ReturnType;

typedef enum{
	FALSE,
	TRUE
}ConditionReturn;

typedef enum{
	DISABLE,
	ENABLE
}Boolean;

#endif
