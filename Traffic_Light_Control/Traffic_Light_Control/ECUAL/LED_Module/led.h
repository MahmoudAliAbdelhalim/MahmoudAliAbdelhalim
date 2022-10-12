 /* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<LED.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR LED MODULE>

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/****************************************************************************************************************************************************************************
 * 																			HEADER FILE GAURD	
 ****************************************************************************************************************************************************************************/
#ifndef LED_H_
#define LED_H_
/******************************************************************************************************************************************************************************
 * 																				INCLUDES
 ******************************************************************************************************************************************************************************/
#include "../../Utilities/std_types.h"
#include "../../MCAL/DIO_Driver/dio.h"
/******************************************************************************************************************************************************************************
 * 																			 ENUMERATIONS
 ******************************************************************************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_LED_configurationError_t
	[Enumeration Description]: This enumeration for led configuration errors
	[Enumeration Members]:
		1. LED_OK -> 0
		2. LED_INVALID_PIN -> 1
		3. LED_INVALID_PORT -> 2
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum 
{
	LED_OK, LED_INVALID_PIN, LED_INVALID_PORT
}EN_LED_configurationError_t;
/****************************************************************************************************************************************************************************
 * 																				STRUCTURES
 ****************************************************************************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Structure Name]: ST_LED_Cofiguration_t
	[Structure Description]: This structure for maintaining Led Configurations.
	[Structure Members]:
		1. LED_portNumber ENUM from EN_DIO_configPorts_t enumeration type to store Led port number
		2. LED_pinNumber ENUM  from EN_DIO_configPins_t enumeration type to store Led pin number
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct 
{
	EN_DIO_configPorts_t LED_portNumber;
	EN_DIO_configPins_t LED_pinNumber;
}ST_LED_Cofiguration_t;
/****************************************************************************************************************************************************************************
 * 																			FUNCTIONS PROTOTYPES
 ****************************************************************************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_init
	[Description]:	 This function is responsible for initialization of the Led by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_init (ST_LED_Cofiguration_t *LED_configPtr);

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_off
	[Description]:	 This function is responsible for turning the Led off by its configurations that
					 given to function and writing on its pin value with zero or LOGIC_LOW.
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_off (ST_LED_Cofiguration_t *LED_configPtr);

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_on
	[Description]:	 This function is responsible for turning the Led off by its configurations that
					 given to function writing on its pin value with one or LOGIC_HIGH.
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_on (ST_LED_Cofiguration_t *LED_configPtr);

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: LED_toggle
	[Description]:	 This function is responsible for toggle the Led status by its configurations that
					 given to function
	[Arguments]
	[in]:			 LED_configPtr Pointer to structure from ST_LED_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_LED_configurationError_t enum type
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_LED_configurationError_t LED_toggle (ST_LED_Cofiguration_t *LED_configPtr);

#endif /* LED_H_ */