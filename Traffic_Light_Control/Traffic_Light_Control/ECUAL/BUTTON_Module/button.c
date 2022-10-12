 /* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<BUTTON.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR PUSH-BUTTON MODULE>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 /****************************************************************************************************************************************************************************
 * 																				INCLUDES
 ****************************************************************************************************************************************************************************/
#include "button.h"
/*****************************************************************************************************************************************************************************
* 																		Functions Definitions
 *****************************************************************************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: BUTTON_init
	[Description]:	 This function is responsible for initialization of the Button by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 BUTTON_configPtr Pointer to structure from ST_BUTTON_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_BUTTON_configurationError_t enum type 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_BUTTON_configurationError_t BUTTON_init(ST_BUTTON_Cofiguration_t *BUTTON_configPtr)
{
	/****************** Test 1 for check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value if it exists between 0 -> 7 ******************/
	if(BUTTON_configPtr->BUTTON_pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return BUTTON_INVALID_PIN;
	}
	/****************** Test 2 for checking if the input port number is greater than NUM_OF_PORTS value if it exists between 0 -> 3 ******************/
	else if(BUTTON_configPtr->BUTTON_portNumber >= NUM_OF_PORTS)
	{
		return BUTTON_INVALID_PORT;
	}
	/****************** if the input pin number is less than NUM_OF_PINS_PER_PORT value & the input port number is less than NUM_OF_PORTS value ******************/
	else
	{
		/* initialize the button pin by its port number , pin number and set the button pin direction as input pin*/
		DIO_initPin(BUTTON_configPtr->BUTTON_portNumber,BUTTON_configPtr->BUTTON_pinNumber, PIN_INPUT);
		return BUTTON_OK;
	}
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: BUTTON_getStatus
	[Description]:	 This function is responsible for reading the pin status of the Button if it is pressed or not 
					 by the structure that given to function 
	[Arguments]
	[in]:			 BUTTON_configPtr Pointer to structure from ST_BUTTON_Cofiguration_t structure type.		 
	[out]:			 buttonPinValue Pointer to character to store reading of the button pin value
	[Return]:		 Enumeration member of configuration errors from EN_BUTTON_configurationError_t enum type 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_BUTTON_configurationError_t BUTTON_getStatus(ST_BUTTON_Cofiguration_t *BUTTON_configPtr, uint8 *buttonPinValue)
{
	/****************** Test 1 for check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value if it exists between 0 -> 7 ******************/
	if(BUTTON_configPtr->BUTTON_pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return BUTTON_INVALID_PIN;
	}
	/****************** Test 2 for checking if the input port number is greater than NUM_OF_PORTS value if it exists between 0 -> 3 ******************/
	else if(BUTTON_configPtr->BUTTON_portNumber >= NUM_OF_PORTS)
	{
		return BUTTON_INVALID_PORT;
	}
	/****************** if the input pin number is less than NUM_OF_PINS_PER_PORT value & the input port number is less than NUM_OF_PORTS value ******************/
	else
	{
		/* get the status of button pin if it (logic high = 1) of (logic low = 0) and store it into Button_pinValue */
		DIO_readPin(BUTTON_configPtr->BUTTON_portNumber,BUTTON_configPtr->BUTTON_pinNumber,buttonPinValue);
		return BUTTON_OK;
	}
}