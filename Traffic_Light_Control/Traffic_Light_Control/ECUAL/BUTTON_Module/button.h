 /* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<BUTTON.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR PUSH-BUTTON MODULE>

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/****************************************************************************************************************************************************************************
 * 																			HEADER FILE GAURD	
 ****************************************************************************************************************************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_
/****************************************************************************************************************************************************************************
 * 																				INCLUDES
 ****************************************************************************************************************************************************************************/
#include "../../Utilities/std_types.h"
#include "../../MCAL/DIO_Driver/dio.h"
/****************************************************************************************************************************************************************************
 * 																		      ENUMERATIONS
 ****************************************************************************************************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_BUTTON_configurationError_t
	[Enumeration Description]: This enumeration for button configuration errors
	[Enumeration Members]:
		1. BUTTON_OK -> 0
		2. BUTTON_INVALID_PIN -> 1 
		3. BUTTON_INVALID_PORT -> 2
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	BUTTON_OK, BUTTON_INVALID_PIN, BUTTON_INVALID_PORT
}EN_BUTTON_configurationError_t;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Structure Name]: ST_BUTTON_Cofiguration_t
	[Structure Description]: This structure for maintaining Button Configurations.
	[Structure Members]:
		1. BUTTON_portNumber ENUM from EN_DIO_configPorts_t enumeration type to store Button port number
		2. BUTTON_pinNumber ENUM  from EN_DIO_configPins_t enumeration type to store Button pin number
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct 
{
	EN_DIO_configPorts_t BUTTON_portNumber;
	EN_DIO_configPins_t BUTTON_pinNumber;
}ST_BUTTON_Cofiguration_t;

/***************************************************************************************************************************************************************************
* 																		FUNCTIONS PROTOTYPES
 ***************************************************************************************************************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: BUTTON_init
	[Description]:	 This function is responsible for initialization of the Button by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 BUTTON_configPtr Pointer to structure from ST_BUTTON_Cofiguration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_BUTTON_configurationError_t enum type 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_BUTTON_configurationError_t BUTTON_init(ST_BUTTON_Cofiguration_t *BUTTON_configPtr);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: BUTTON_getStatus
	[Description]:	 This function is responsible for reading the pin status of the Button if it is pressed or not 
					 by the structure that given to function 
	[Arguments]
	[in]:			 BUTTON_configPtr Pointer to structure from ST_BUTTON_Cofiguration_t structure type.		 
	[out]:			 buttonPinValue Pointer to character to store reading of the button pin value
	[Return]:		 Enumeration member of configuration errors from EN_BUTTON_configurationError_t enum type 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_BUTTON_configurationError_t BUTTON_getStatus(ST_BUTTON_Cofiguration_t *BUTTON_configPtr, uint8 *buttonPinValue);


#endif /* BUTTON_H_ */