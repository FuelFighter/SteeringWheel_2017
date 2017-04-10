/*
 * buttons_management.h
 *
 * Created: 04.04.2017 16:55:26
 *  Author: ola
 */ 


#ifndef BUTTONS_MANAGEMENT_H_
#define BUTTONS_MANAGEMENT_H_
#include <stdbool.h>
#include "UniversalModuleDrivers/adc.h"
#include "calibrate.h"

typedef enum {
	joyButton = PINB0,
	horn = PINB1,
	cruiseControl = PINB2,
	left = PINB3,
	right = PINB4
} button_t;

typedef enum {
	joyX = CH_ADC2,
	joyZ = CH_ADC3,
	thrR = CH_ADC1,
	thrL = CH_ADC0
} adc_t;

void buttons_init();
bool button_is_pressed(button_t button);
uint16_t cal_adc_read(adc_t adc_val, uint16_t min, uint16_t max);

#endif /* BUTTONS_MANAGEMENT_H_ */