/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic.h"
#include "mcu_hw.h"
#include "Nvic_cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define NVIC_GROUPING_SYSTEM_XXX			4
#define	NVIC_GROUPING_SYSTEM_XXY			5
#define	NVIC_GROUPING_SYSTEM_XYY			6
#define	NVIC_GROUPING_SYSTEM_YYY			7

#define APINT_VECTKEY 						0x05FA
#define APINT_VECTKEY_FIRLED_OFFSET 		16u
#define priorGROUP_FIELED_OFFSET			0x8u
#define NVIC_REG_NUM_OF_prior_FIELDS		4u

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : NVIC_init(void)        
* \Description     : NVIC initialization                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : void
*******************************************************************************/
void NVIC_init(void)
{
	Nvic_IntType intNum;
	uint8 Group, SubGroup, GroupingField, i;
	uint32 enRegOffset, enBitOffset, priorRegOffset, priorBitOffset;

	
	/* configure grouping and subgrouping int APINT register in SCB */
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIRLED_OFFSET)
					|(NVIC_GROUPING_SYSTEM << priorGROUP_FIELED_OFFSET);
	
	for(i=0; i< NVIC_ACTIVATED_INT_SIZE ;i++)
	{
		intNum			= NVIC_Cfg[i].Interupt_Number;
		Group		= NVIC_Cfg[i].Group_priorority;
		SubGroup = NVIC_Cfg[i].SubGroup_priorority;
		
		/* enable\disable based on user configuration */
		enRegOffset = (intNum/WORD_LENGTH_BITS)*WORD_LENGTH_BYTES;
		enBitOffset = intNum%WORD_LENGTH_BITS;	
		GET_HWREG(NVIC_BASE_ADDRESS,enRegOffset) |= (1 << enBitOffset);
				
		
#if NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX
	GroupingField = Group;
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY
	GroupingField = ((Group<<1)&0x6) | (SubGroup&0x1);
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY
	GroupingField = ((Group<<2)&0x4) | (SubGroup&0x3);
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY
	GroupingField = Group;
#else
     #error SELECTION INVALID			
#endif
			
			/* asign group\subgroup priorority */
		
			priorRegOffset = (intNum/NVIC_REG_NUM_OF_prior_FIELDS)*WORD_LENGTH_BYTES;
			priorBitOffset = 5 + (8 * (intNum%NVIC_REG_NUM_OF_prior_FIELDS));
			GET_HWREG(NVIC_prior_BASE_ADDRESS,priorRegOffset) |= (GroupingField << priorBitOffset);
		
		
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/

