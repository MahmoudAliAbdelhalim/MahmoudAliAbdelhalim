 /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<LED.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR LED MODULE>

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 /******************************************************************************************************************************************************************************
 * 																				INCLUDES
 *******************************************************************************************************************************************************************************/
#include "led.h"
/*******************************************************************************************************************************************************************************
* 																			Functions Definitions
 ******************************************************************************************************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_init
	[Description]:	 This function is responsible for initialization of the Led by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_init(ST_LED_Cofiguration_t *LED_configPtr)
{
	/****************** Test 1 for check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value if it exists between 0 -> 7 ******************/
	if(LED_configPtr->LED_pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return LED_INVALID_PIN;
	}
	/****************** Test 2 for checking if the input port number is greater than NUM_OF_PORTS value if it exists between 0 -> 3 ******************/
	else if(LED_configPtr->LED_portNumber >= NUM_OF_PORTS)
	{
		return LED_INVALID_PORT;
	}
	/****************** if the input pin number is less than NUM_OF_PINS_PER_PORT value & the input port number is less than NUM_OF_PORTS value ******************/
	else
	{
		/* initialize the led pin by its port number1, pin number and set the led pin direction as output pin */
		DIO_initPin(LED_configPtr->LED_portNumber, LED_configPtr->LED_pinNumber, PIN_OUTPUT);
		return LED_OK;
	}	
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_off
	[Description]:	 This function is responsible for turning the Led off by its configurations that
					 given to function and writing on its pin value with zero or LOGIC_LOW.
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_off(ST_LED_Cofiguration_t *LED_configPtr)
{
	/****************** Test 1 for check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value if it exists between 0 -> 7 ******************/
	if(LED_configPtr->LED_pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return LED_INVALID_PIN;
	}
	/****************** Test 2 for checking if the input port number is greater than NUM_OF_PORTS value if it exists between 0 -> 3 ******************/
	else if(LED_configPtr->LED_portNumber >= NUM_OF_PORTS)
	{
		return LED_INVALID_PORT;
	}
	/****************** if the input pin number is less than NUM_OF_PINS_PER_PORT value & the input port number is less than NUM_OF_PORTS value ******************/
	else
	{	
		/* turn the led off by the led pin by its port number1, pin number and setting the pin value with logic low or zero value.*/
		DIO_writePin(LED_configPtr->LED_portNumber,LED_configPtr->LED_pinNumber, LOGIC_LOW);
		return LED_OK;
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_on
	[Description]:	 This function is responsible for turning the Led off by its configurations that
					 given to function writing on its pin value with one or LOGIC_HIGH.
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_on(ST_LED_Cofiguration_t *LED_configPtr)
{
	/****************** Test 1 for check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value if it exists between 0 -> 7 ******************/
	if(LED_configPtr->LED_pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return LED_INVALID_PIN;
	}
	/****************** Test 2 for checking if the input port number is greater than NUM_OF_PORTS value if it exists between 0 -> 3 ******************/
	else if(LED_configPtr->LED_portNumber >= NUM_OF_PORTS)
	{
		return LED_INVALID_PORT;
	}
	/****************** if the input pin number is less than NUM_OF_PINS_PER_PORT value & the input port number is less than NUM_OF_PORTS value ******************/
	else
	{
		/* turn the led on by the led pin by its port number1, pin number and setting the pin value with logic high or one value */
		DIO_writePin(LED_configPtr->LED_portNumber, LED_configPtr->LED_pinNumber, LOGIC_HIGH);
		return LED_OK;
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_toggle
	[Description]:	 This function is responsible for toggle the Led status by its configurations that
					 given to function
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_toggle(ST_LED_Cofiguration_t *LED_configPtr)
{
	/****************** Test 1 for check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value if it exists between 0 -> 7 ******************/
	if(LED_configPtr->LED_pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return LED_INVALID_PIN;
	}
	/****************** Test 2 for checking if the input port number is greater than NUM_OF_PORTS value if it exists between 0 -> 3 ******************/
	else if(LED_configPtr->LED_portNumber >= NUM_OF_PORTS)
	{
		return LED_INVALID_PORT;
	}
	/****************** if the input pin number is less than NUM_OF_PINS_PER_PORT value & the input port number is less than NUM_OF_PORTS value ******************/
	else
	{
		/* toggle the led status by toggling the led pin state */
		DIO_togglePin(LED_configPtr->LED_portNumber, LED_configPtr->LED_pinNumber);
		return LED_OK;		
	}
}