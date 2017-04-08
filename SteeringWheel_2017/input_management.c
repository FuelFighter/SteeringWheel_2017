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

uint16_t cal_adc_read(adc_t adc_val, uint16_t min, uint16_t max) {
	float min_f = (float)min;
	float max_f = (float)max;
	float adc_f = (float)adc_read(adc_val);
	float result_f = ( (adc_f - min_f) / ( (max_f - min_f) / 100 ) );
	return (uint16_t)result_f;
}