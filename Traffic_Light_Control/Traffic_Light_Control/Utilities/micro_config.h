 /* -----------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<MICRO_CONFIG.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]:  <HEADER FILE FOR INCLUDE ALL MICROCONTROLLER LIBRARIES>

-------------------------------------------------------------------------------------------------------------*/

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */