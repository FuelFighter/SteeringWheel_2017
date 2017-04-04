/*
 * SteeringWheel_2017.c
 *
 * Created: 18/03/17 15:13:44
 * Author : Sondre
 */ 

#include <avr/io.h>
// #include "adc.h"
#include "usbdb.h"
#include <util/delay.h>
#include "UniversalModuleDrivers/adc.h"

int main(void)
{
	// adc_init();
	PORTB |= (1<<PB4); //Initiate (input) PE3, indicator left
	DDRB &= ~(1<<PB4);
	
	PORTB |= (1<<PB3); //Initiate (input) PE4, indicator right
	DDRB &= ~(1<<PB3);
	
	PORTB |= (1<<PB1); //Initiate (input) PB4, horn
	DDRB &= ~(1<<PB1);
	
	PORTB |= (1<<PB2); //Initiate (input) PB4, CRUISE CONTROL
	DDRB &= ~(1<<PB2);
	
	PORTB |= (1<<PB0); //Initiate (input) PB4, joy button
	DDRB &= ~(1<<PB0);
	
	usbdbg_init();
	
	while (1)
	{
		if (!((1<<PINB0)&PINB)) {
			printf("joy button ;) \n");
		}
		if (!((1<<PINB1)&PINB)) {
			printf("horn \n");
		}
		if (!((1<<PINB2)&PINB)) {
			printf("cruise control \n");
		}
		if (!((1<<PINB3)&PINB)) {
			printf("indicator right \n");
		}
		if (!((1<<PINB4)&PINB)) {
			printf("indicator left \n");
		}
		_delay_ms(10);
	}
}
