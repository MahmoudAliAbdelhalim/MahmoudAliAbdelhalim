 /* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<DIO.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR AVR-ATMEGA32 DIGITAL INPUTS/OUPUTS DRIVER>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/****************************************************************************************************************************************************************************
 * 																			INCLUDES
 ****************************************************************************************************************************************************************************/
#include "dio.h"
/****************************************************************************************************************************************************************************
 * 																		FUNCTIONS DEFINITIONS
 ****************************************************************************************************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_initPin
	[Description]:	 This function is responsible for initialization of pin configuration by its port number, 
					 pin number and pin direction.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enum type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enum type.
	[in3]:			 Enumeration member of pin direction from EN_DIO_portDirection_t enum type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_initPin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber, EN_DIO_pinDirection_t pinDirection)
{
	/************** Test 1 for checking the given pin number if it exists between 0 -> 7 **************/
	/* check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value */
	if(pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return INVALID_PIN;
	}
	/* if the input pin number is less than NUM_OF_PINS_PER_PORT value */
	else
	{
		/************************ Test 2 for checking the given port number if it exists between 0 -> 3 ************************/
		switch(portNumber)
		{
			case PORTA_ID :
				/* Test 3 for checking the given pin direction if it is input or output direction */
				/* a. check if the required direction is an output direction */
				if(pinDirection == PIN_OUTPUT)
				{
					/* set pin as an output pin by setting the bit by its pin number in data direction register of port A by 1 */
					SET_BIT(DDRA,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required direction is an input direction */
				else if(pinDirection == PIN_INPUT)
				{
					/* set pin as an input pin by clearing the bit by its pin number in data direction register of port A by 0 */
					CLEAR_BIT(DDRA,pinNumber);
					return DIO_OK;
				}
				/* c. if the required direction is not valid */
				else
				{
					return INVALID_DIRECTION;
				}
			
			case PORTB_ID :
				/************************ Test 3 for checking the given pin direction if it is input or output direction ************************/
				/* a. check if the required direction is an output direction */
				if(pinDirection == PIN_OUTPUT)
				{
					/* set pin as an output pin by setting the bit by its pin number in data direction register of port B by 1 */
					SET_BIT(DDRB,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required direction is an input direction */
				else if(pinDirection == PIN_INPUT)
				{
					/* set pin as an input pin by clearing the bit by its pin number in data direction register of port B by 0 */
					CLEAR_BIT(DDRB,pinNumber);
					return DIO_OK;
				}
				/* c. if the required direction is not valid */
				else
				{
					return INVALID_DIRECTION;
				}
			
			case PORTC_ID :
				/************************ Test 3 for checking the given pin direction if it is input or output direction ************************/
				/* a. check if the required direction is an output direction */				
				if(pinDirection == PIN_OUTPUT)
				{
					/* set pin as an output pin by setting the bit by its pin number in data direction register of port C by 1 */
					SET_BIT(DDRC,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required direction is an input direction */
				else if(pinDirection == PIN_INPUT)
				{
					/* set pin as an input pin by clearing the bit by its pin number in data direction register of port C by 0 */
					CLEAR_BIT(DDRC,pinNumber);
					return DIO_OK;
				}
				/* c. if the required direction is not valid */
				else
				{
					return INVALID_DIRECTION;
				}
			
			case PORTD_ID :
				/************************ Test 3 for checking the given pin direction if it is input or output direction ************************/
				/* a. check if the required direction is an output direction */			
				if(pinDirection == PIN_OUTPUT)
				{
					/* set pin as an output pin by setting the bit by its pin number in data direction register of port D by 1 */
					SET_BIT(DDRD,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required direction is an input direction */
				else if(pinDirection == PIN_INPUT)
				{
					/* set pin as an input pin by clearing the bit by its pin number in data direction register of port D by 0 */
					CLEAR_BIT(DDRD,pinNumber);
					return DIO_OK;
				}
				/* c. if the required direction is not valid */
				else
				{
					return INVALID_DIRECTION;
				}
			
			default:
					return INVALID_PORT;
		}
	}
	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_writePin
	[Description]:	 This function is responsible for writing a value on the pin by its port number, pin number
					 and pin value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enumeration type.
	[in3]:			 Unsigned character variable called pinValue to store pin value that be written.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_writePin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber, uint8 pinValue)

{
	/************************ Test 1 for checking the given pin number if it exists between 0 -> 7 ************************/
	/* check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value */
	if(pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return INVALID_PIN;
	}
	/* if the input pin number is less than NUM_OF_PINS_PER_PORT value */
	else
	{
		/************************ Test 2 for checking the given port number if it exists between 0 -> 3 ************************/
		switch(portNumber)
		{
			case PORTA_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(pinValue == LOGIC_HIGH)
				{
					/* set pin value to high by setting the bit by its pin number in data register port A by 1 */
					SET_BIT(PORTA,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(pinValue == LOGIC_LOW)
				{
					/* set pin value to low by clearing the bit by its pin number in data register port A by 0 */
					CLEAR_BIT(PORTA,pinNumber);
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
				break;
			
			case PORTB_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(pinValue == LOGIC_HIGH)
				{
					/* set pin value to high by setting the bit by its pin number in data register port A by 1 */
					SET_BIT(PORTB,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(pinValue == LOGIC_LOW)
				{
					/* set pin value to low by clearing the bit by its pin number in data register port A by 0 */
					CLEAR_BIT(PORTB,pinNumber);
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
				break;
			
			case PORTC_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(pinValue == LOGIC_HIGH)
				{
					/* set pin value to high by setting the bit by its pin number in data register port A by 1 */
					SET_BIT(PORTC,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(pinValue == LOGIC_LOW)
				{
					/* set pin value to low by clearing the bit by its pin number in data register port A by 0 */
					CLEAR_BIT(PORTC,pinNumber);
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
				break;
			
			case PORTD_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(pinValue == LOGIC_HIGH)
				{
					/* set pin value to high by setting the bit by its pin number in data register port A by 1 */
					SET_BIT(PORTD,pinNumber);
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(pinValue == LOGIC_LOW)
				{
					/* set pin value to low by clearing the bit by its pin number in data register port A by 0 */
					CLEAR_BIT(PORTD,pinNumber);
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
				break;
			
			/* if the input port number is not valid */
			default:
				return INVALID_PORT;
		}
	}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_readPin
	[Description]:	 This function is responsible for reading the pin value by its port number, pin number
					 and pin value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enumeration type.
	[in3]:			 Unsigned character pointer variable called pinValue to store pin value that be read.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_readPin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber, uint8 *pinValue)
{
	/* set the pinValue pointer value to zero to get the new pin value */
	*pinValue = LOGIC_LOW;
	
	/************************ Test 1 for checking the given pin number if it exists between 0 -> 7 ************************/
	/* check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value */
	if(pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return INVALID_PIN;
	}
	/* if the input pin number is less than NUM_OF_PINS_PER_PORT value */
	else
	{
		/************************ Test 2 for checking the given port number if it exists between 0 -> 3 ************************/
		switch(portNumber)
		{
			case PORTA_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(BIT_IS_SET(PINA,pinNumber))
				{
					/* set the pinValue pointer value to high or 1 */
					*pinValue = LOGIC_HIGH;
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(BIT_IS_CLEAR(PINA,pinNumber))
				{
					/* set the pinValue pointer value to low or 0 */
					*pinValue = LOGIC_LOW;
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
				
			case PORTB_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(BIT_IS_SET(PINB,pinNumber))
				{
					/* set the pinValue pointer value to high or 1 */
					*pinValue = LOGIC_HIGH;
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(BIT_IS_CLEAR(PINB,pinNumber))
				{
					/* set the pinValue pointer value to low or 0 */
					*pinValue = LOGIC_LOW;
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
			
			case PORTC_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(BIT_IS_SET(PINC,pinNumber))
				{
					/* set the pinValue pointer value to high or 1 */
					*pinValue = LOGIC_HIGH;
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(BIT_IS_CLEAR(PINC,pinNumber))
				{
					/* set the pinValue pointer value to low or 0 */
					*pinValue = LOGIC_LOW;
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
			
			case PORTD_ID :
				/************************ Test 3 for checking the required pin value if it is high or low ************************/
				/* a. check if the required pin value is HIGH  */
				if(BIT_IS_SET(PIND,pinNumber))
				{
					/* set the pinValue pointer value to high or 1 */
					*pinValue = LOGIC_HIGH;
					return DIO_OK;
				}
				/* b. check if the required pin value is LOW */
				else if(BIT_IS_CLEAR(PIND,pinNumber))
				{
					/* set the pinValue pointer value to low or 0 */
					*pinValue = LOGIC_LOW;
					return DIO_OK;
				}
				/* c. if the required pin value is not valid */
				else
				{
					return INVALID_VALUE;
				}
				
			/* if the input port number is not valid */
			default:
				return INVALID_PORT;
		}
	}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_togglePin
	[Description]:	 This function is responsible for toggle the pin value by its port number, pin number.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of pin number from EN_DIO_configPins_t enumeration type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_togglePin(EN_DIO_configPorts_t portNumber, EN_DIO_configPins_t pinNumber)
{
	/************************ Test 1 for checking the given pin number if it exists between 0 -> 7 ******************************/
	/* check if the  input pin number is greater than NUM_OF_PINS_PER_PORT value */
	if(pinNumber >= NUM_OF_PINS_PER_PORT)
	{
		return INVALID_PIN;
	}
	/* if the input pin number is less than NUM_OF_PINS_PER_PORT value */
	else
	{
		/************************ Test 2 for checking the given port number if it exists between 0 -> 3 ************************/
		switch(portNumber)
		{
			case PORTA_ID :
				TOGGLE_BIT(PORTA,pinNumber);
				return DIO_OK;
				
			case PORTB_ID :
				TOGGLE_BIT(PORTB,pinNumber);
				return DIO_OK;

			case PORTC_ID :
				TOGGLE_BIT(PORTC,pinNumber);
				return DIO_OK;
			
			case PORTD_ID :
				TOGGLE_BIT(PORTD,pinNumber);
				return DIO_OK;
				
			/* if the input port number is not valid */	
			default:
				return INVALID_PORT;
		}
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_initPort
	[Description]:	 This function is responsible for initialization the port configuration by its port number
					 and port direction.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Enumeration member of port direction from EN_DIO_portDirection_t enumeration type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_initPort(EN_DIO_configPorts_t portNumber, EN_DIO_portDirection_t portDirection)
{
	/************************ Test 1 for checking the given port number if it exists between 0 -> 3 ************************/
	switch(portNumber)
	{
		case PORTA_ID :
			/************************ Test 2 for checking the given pin direction if it is input or output direction ************************/
			/* a. check if the required direction is an output direction */
			if(portDirection == PORT_OUTPUT)
			{
				/* set pin as an output pin by setting the data direction register of port A by 0xFF */
				SET_PORT(DDRA);
				return DIO_OK;
			}
			/* b. check if the required direction is an input direction */
			else if(portDirection == PORT_INPUT)
			{
				/* set pin as an input pin by clearing the data direction register of port A by 0 */
				CLEAR_PORT(DDRA);
				return DIO_OK;
			}
			/* c. if the required direction is not valid */
			else
			{
				return INVALID_DIRECTION;
			}

		case PORTB_ID :
			/************************ Test 2 for checking the given pin direction if it is input or output direction ************************/
			/* a. check if the required direction is an output direction */
			if(portDirection == PORT_OUTPUT)
			{
				/* set pin as an output pin by setting the data direction register of port B by 0xFF */
				SET_PORT(DDRB);
				return DIO_OK;
			}
			/* b. check if the required direction is an input direction */
			else if(portDirection == PORT_INPUT)
			{
				/* set pin as an input pin by clearing the data direction register of port B by 0 */
				CLEAR_PORT(DDRB);
				return DIO_OK;
			}
			/* c. if the required direction is not valid */
			else
			{
				return INVALID_DIRECTION;
			}

		case PORTC_ID :
			/************************ Test 2 for checking the given pin direction if it is input or output direction ************************/
			/* a. check if the required direction is an output direction */
			if(portDirection == PORT_OUTPUT)
			{
				/* set pin as an output pin by setting the data direction register of port C by 0xFF */
				SET_PORT(DDRC);
				return DIO_OK;
			}
			/* b. check if the required direction is an input direction */
			else if(portDirection == PORT_INPUT)
			{
				/* set pin as an input pin by clearing the data direction register of port C by 0 */
				CLEAR_PORT(DDRC);
				return DIO_OK;
			}
			/* c. if the required direction is not valid */
			else
			{
				return INVALID_DIRECTION;
			}

		case PORTD_ID :
			/************************ Test 2 for checking the given pin direction if it is input or output direction ************************/
			/* a. check if the required direction is an output direction */
			if(portDirection == PORT_OUTPUT)
			{
				/* set pin as an output pin by setting the data direction register of port D by 0xFF */
				SET_PORT(DDRD);
				return DIO_OK;
			}
			/* b. check if the required direction is an input direction */
			else if(portDirection == PORT_INPUT)
			{
				/* set pin as an input pin by clearing the data direction register of port D by 0 */
				CLEAR_PORT(DDRD);
				return DIO_OK;
			}
			/* c. if the required direction is not valid */
			else
			{
				return INVALID_DIRECTION;
			}
			
		/* if the input port number is not valid */
		default:
			return INVALID_PORT;
		}
	}
	

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_writePort
	[Description]:	 This function is responsible for writing a value on the port by its port number and 
					 port value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type..
	[in2]:			 Unsigned character variable called portValue to store port value that be written.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_writePort(EN_DIO_configPorts_t portNumber, uint8 portValue)
{
	/************************ Test 1 for checking the given port number if it exists between 0 -> 3 ************************/
	switch(portNumber)
	{
		case PORTA_ID :
			PORTA = portValue;		// put the input value into the data register PORT A
			return DIO_OK;
		
		case PORTB_ID :
			PORTB = portValue;		// put the input value into the data register PORT B
			return DIO_OK;
			
		case PORTC_ID :
			PORTC = portValue;		// put the input value into the data register PORT C
			return DIO_OK;
		
		case PORTD_ID :
			PORTD = portValue;		// put the input value into the data register PORT D
			return DIO_OK;
			
		/* if the input port number is not valid */
		default:
			return INVALID_PORT;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: DIO_readPort
	[Description]:	 This function is responsible for reading a value of the port by its port number and
					 port value.
	[Arguments]
	[in1]:			 Enumeration member of port number from EN_DIO_configPorts_t enumeration type.
	[in2]:			 Unsigned character pointer variable called portValue to store port value that be read.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_DIO_configurationError_t enum type
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_DIO_configurationError_t DIO_readPort(EN_DIO_configPorts_t portNumber, uint8 *portValue)
{
	/* set the portValue pointer value to zero to get the new port value */
	*portValue = LOGIC_LOW;
	
	/************************ Test 1 for checking the given port number if it exists between 0 -> 3 ************************/
	switch(portNumber)
	{
		case PORTA_ID :
			*portValue = PINA;		// get the port value from the status register PIN A into portValue pointer
			return DIO_OK;
		
		case PORTB_ID :
			*portValue = PINB;		// get the port value from the status register PIN B into portValue pointer
			return DIO_OK;
		
		case PORTC_ID :
			*portValue = PINC;		// get the port value from the status register PIN C into portValue pointer
			return DIO_OK;
		
		case PORTD_ID :
			*portValue = PIND;		// get the port value from the status register PIN D into portValue pointer
			return DIO_OK;
		
		/* if the input port number is not valid */
		default:
		return INVALID_PORT;
	}
}