/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Nvic_Cfg.h
 *       Module:  -
 *
 *  Description:  NVIC configuration     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_CFG_H_
#define NVIC_CFG_H_



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/*
*	choose form the followings
*	NVIC_GROUPING_SYSTEM_XXX : [0-7] Groups, [0]subgroups
*	NVIC_GROUPING_SYSTEM_XXY : [0-3] Groups, [0-1]subgroups
*	NVIC_GROUPING_SYSTEM_XYY : [0-1] Groups, [0-3]subgroups
*	NVIC_GROUPING_SYSTEM_XYY : [0] Groups,	 [0-7]subgroups Non-Preemtion system

*/

#define NVIC_GROUPING_SYSTEM   NVIC_GROUPING_SYSTEM_XXX
#define NVIC_ACTIVATED_INT_SIZE  5


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
