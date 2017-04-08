/*
 * button_init.c
 *
 * Created: 04.04.2017 16:52:44
 *  Author: ola
 */ 

#include <avr/io.h>
#include "input_management.h"
#include "calibrate.h"

void buttons_init() {
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
}

bool button_is_pressed(button_t button) {
	return !((1<<(int)button)&PINB);
}

float cal_adc_read(adc_t adc_val, uint16_t min, uint16_t max) {
	return ( (float)adc_read(adc_val) / ((float)(max - min)/100) );
}