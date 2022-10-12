 /* -----------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<EXTERNAL_INTERRUPT.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR AVR EXTERNAL INTERRUPTS>

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/****************************************************************************************************************************************************************************
 * 																				INCLUDES
 ****************************************************************************************************************************************************************************/
#include "external_interrupt.h"
/****************************************************************************************************************************************************************************
 *                      													Global Variables
 ****************************************************************************************************************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static void (*g_EXT_INT0_callBackPtr)(void) = NULL_PTR;
static void (*g_EXT_INT1_callBackPtr)(void) = NULL_PTR;
static void (*g_EXT_INT2_callBackPtr)(void) = NULL_PTR;
/****************************************************************************************************************************************************************************
 *                      												Interrupt Service Routines
 ****************************************************************************************************************************************************************************/

/************************************ EXTERNAL INTERRUPT 0 ************************************************/
ISR(INT0_vect)
{
	if(g_EXT_INT0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_EXT_INT0_callBackPtr)();
	}
}
/************************************ EXTERNAL INTERRUPT 1 ************************************************/
ISR(INT1_vect)
{
	if(g_EXT_INT1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_EXT_INT1_callBackPtr)();
	}
}
/************************************ EXTERNAL INTERRUPT 2 ************************************************/
ISR(INT2_vect)
{
	if(g_EXT_INT2_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_EXT_INT2_callBackPtr)();
	}
}
/****************************************************************************************************************************************************************************
 * 																	Functions Definition
 ****************************************************************************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: EXT_INT_init
	[Description]:	 This function is responsible for initialization of External Interrupt by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 EXT_INT_configPtr Pointer to structure from ST_EXTERNAL_INTERRUPT_Configuration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_EXT_INT_configurationError_t enum type
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_EXT_INT_configurationError_t EXT_INT_init(ST_EXTERNAL_INTERRUPT_Configuration_t *EXT_INT_configPtr)
{
	/*********** Test 1 for checking the given external interrupt id if it exists between EN_EXT_INT_ID_t enum members (0 -> 2) **************/
	switch(EXT_INT_configPtr->EXT_INT_ID)
	{
		/************************************ External Interrupt 0 ************************************************/
		case EXT_INT0:
			/* SET External Interrupt Request 0 Enable INT0 Bit in General Interrupt Control Register GICR */
			SET_BIT(GICR,INT0);
			/*********** Test 2 for checking the input sense control if it is exceeded the last sense **************/
			if( ((EXT_INT_configPtr->EXT_INT_SENSE_CONTROL) < LOW_LEVEL) || ((EXT_INT_configPtr->EXT_INT_SENSE_CONTROL) > RISING_EDGE) )
			{
				return EXT_INT_INVALID_SENSE_CONTROL;
			}
			else
			{
				/* SET Interrupt 0 Sense Control ISC00 and ISC01 Bits in MCU Control Register MCUCR */
				MCUCR = (MCUCR & 0xFC) | (EXT_INT_configPtr->EXT_INT_SENSE_CONTROL);
				return EXT_INT_OK;				
			}			

		/************************************ External Interrupt 1 ************************************************/	
		case EXT_INT1:
			/* SET External Interrupt Request 1 Enable INT1 Bit in General Interrupt Control Register GICR */
			SET_BIT(GICR,INT1);
			/*********** Test 2 for checking the input sense control if it is exceeded the last sense **************/
			if( ((EXT_INT_configPtr->EXT_INT_SENSE_CONTROL) < LOW_LEVEL) || ((EXT_INT_configPtr->EXT_INT_SENSE_CONTROL) > RISING_EDGE) )
			{
				return EXT_INT_INVALID_SENSE_CONTROL;
			}
			else
			{
				/* SET Interrupt 1 Sense Control ISC10 and ISC11 Bits in MCU Control Register MCUCR */
				MCUCR = (MCUCR & 0xF3) | (EXT_INT_configPtr->EXT_INT_SENSE_CONTROL);
				return EXT_INT_OK;			
			}	
		/************************************ External Interrupt 2 ************************************************/	
		case EXT_INT2:
			/* SET External Interrupt Request 2 Enable INT2 Bit in General Interrupt Control Register GICR */
			SET_BIT(GICR,INT2);	
			/*********** Test 2 for checking the input sense control if it is exceeded the last sense **************/
			if( ((EXT_INT_configPtr->EXT_INT_SENSE_CONTROL) < LOW_LEVEL) || ((EXT_INT_configPtr->EXT_INT_SENSE_CONTROL) > RISING_EDGE) )
			{
				return EXT_INT_INVALID_SENSE_CONTROL;
			}			
			else
			{
				/* SET Interrupt 2 Sense Control ISC2 Bit in MCU Control and Status Register MCUCSR */
				MCUCSR = (MCUCSR & 0xBF) | (0x01 & EXT_INT_configPtr->EXT_INT_SENSE_CONTROL);
				return EXT_INT_OK;
			}	
		/************************************ External Interrupt INVALID ************************************************/
		default:
			return EXT_INT_INVALID_ID;
	}

}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: EXT_INT_setCallBack
	[Description]:	 This function is responsible for call the passed function by External Interrupt Service Request
	[Arguments]
	[in1]:			 EXT_INT_ID of the Timer from EN_EXT_INT_ID_t enum type.
	[in]:			 func_ptr Pointer to Function that 'll be called back by EXTERNAL INTERRUPT ISR
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_EXT_INT_configurationError_t enum type
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_EXT_INT_configurationError_t EXT_INT_setCallBack(EN_EXT_INT_ID_t EXT_INT_ID,void(*func_ptr)(void))
{
	/*********** Test 1 for checking the given external interrupt id if it exists between EN_EXT_INT_ID_t enum members (0 -> 2) **************/
	switch(EXT_INT_ID)
	{
		/************************************ External Interrupt 0 ************************************************/
		case EXT_INT0:
			/* Save the address of the Call back function in a global variable */
			g_EXT_INT0_callBackPtr = func_ptr;
			return EXT_INT_OK;
		/************************************ External Interrupt 1 ************************************************/
		case EXT_INT1:
			/* Save the address of the Call back function in a global variable */
			g_EXT_INT1_callBackPtr = func_ptr;
			return EXT_INT_OK;
		/************************************ External Interrupt 2 ************************************************/
		case EXT_INT2:
			/* Save the address of the Call back function in a global variable */
			g_EXT_INT2_callBackPtr = func_ptr;
			return EXT_INT_OK;
		/************************************ External Interrupt INVALID ************************************************/
		default:
			return EXT_INT_INVALID_ID;
	}
}