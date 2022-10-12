/* -----------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<DIO.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR DIGITAL INPUTS/OUTPUTS DRIVER >

-------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************
 * 											HEADER FILE GAURD	
 **********************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_
/**********************************************************************************************************
 * 												INCLUDES
 **********************************************************************************************************/
#include "../../Utilities/std_types.h"
#include "../../Utilities/common_macros.h"
#include "../../Utilities/micro_config.h"
//#include "../../Utilities/registers.h"
/**********************************************************************************************************
 * 											 ENUMERATIONS
 **********************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_DIO_configPins_t
	[Enumeration Description]: This enumeration for configurable pins
	[Enumeration Members]:
		1. PIN0_ID -> 0
		2. PIN1_ID -> 1
		3. PIN2_ID -> 2
		4. PIN3_ID -> 3
		5. PIN4_ID -> 4
		6. PIN5_ID -> 5
		7. PIN6_ID -> 6
		8. PIN7_ID -> 7
-------------------------------------------------------------------------------------------------------------*/
typedef enum 
{
	PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID, PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID
}EN_DIO_configPins_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_DIO_configPorts_t
	[Enumeration Description]: This enumeration for configurable ports
	[Enumeration Members]:
		1. PORTA_ID -> 0
		2. PORTB_ID -> 1
		3. PORTC_ID -> 2
		4. PORTD_ID -> 3
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID
}EN_DIO_configPorts_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_DIO_PinDirectionType
	[Enumeration Description]: This enumeration for pin direction types
	[Enumeration Members]:
		1. PIN_INPUT -> 0
		2. PIN_OUTPUT -> 1
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}EN_DIO_pinDirection_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_DIO_PortDirectionType
	[Enumeration Description]: This enumeration for port direction types
	[Enumeration Members]:
		1. PORT_INPUT -> 0x00
		2. PORT_OUTPUT -> 0xFF
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}EN_DIO_portDirection_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_DIO_configurationError_t
	[Enumeration Description]: This enumeration for configuration errors
	[Enumeration Members]:
		1. DIO_OK -> 0
		2. INVALID_PORT -> 1
		3. INVALID_PIN -> 2
		4. INVALID_DIRECTION -> 3
		5. INVALID_DATA -> 4
		6. INVALID_VALUE -> 5
-------------------------------------------------------------------------------------------------------------*/
typedef enum  
{
	DIO_OK, INVALID_PORT, INVALID_PIN, INVALID_DIRECTION, INVALID_DATA, INVALID_VALUE
}EN_DIO_configurationError_t;
/*************************************************************************************************************
 * 												DEFINITIONS
 *************************************************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

/************************************************************************************************************
 * 											FUNCTIONS PROTOTYPES
 ************************************************************************************************************/
/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_initPin
	[Description]:	 This function is responsible for initialization of pin configuration by its port number, 
					 pin number and pin direction.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enum type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enum type.
	[in3]:			 Enumeration member of pin direction from EN_DIO_pinDirection_t enum type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_initPin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber, EN_DIO_pinDirection_t pinDirection);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_writePin
	[Description]:	 This function is responsible for writing a value on the pin by its port number, pin number
					 and pin value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enumeration type.
	[in3]:			 Unsigned character variable called pinValue to store pin value that be written.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_writePin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber, uint8 pinValue);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_readPin
	[Description]:	 This function is responsible for reading the pin value by its port number, pin number
					 and pin value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enumeration type.
	[in3]:			 Unsigned character pointer variable called pinValue to store pin value that be read.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_readPin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber, uint8 *pinValue);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_togglePin
	[Description]:	 This function is responsible for toggle the pin value by its port number, pin number.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enumeration type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_togglePin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_initPort
	[Description]:	 This function is responsible for initialization the port configuration by its port number
					 and port direction.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of port direction from EN_DIO_portDirection_t enumeration type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_initPort(EN_DIO_configPorts_t portNumber, EN_DIO_portDirection_t portDirection);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_writePort
	[Description]:	 This function is responsible for writing a value on the port by its port number and 
					 port value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type..
	[in2]:			 Unsigned character variable called portValue to store port value that be written.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_writePort(EN_DIO_configPorts_t portNumber, uint8 portValue);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_readPort
	[Description]:	 This function is responsible for reading a value of the port by its port number and
					 port value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Unsigned character pointer variable called portValue to store port value that be read.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_readPort(EN_DIO_configPorts_t portNumber, uint8 *portValue);

#endif /* DIO_H_ */