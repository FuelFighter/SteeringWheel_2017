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
	JoyButton = PINB0,
	Horn = PINB1,
	CruiseControl = PINB2,
	Left = PINB3,
	Right = PINB4
} button_t;

typedef enum {
	JoyX = CH_ADC2,
	JoyZ = CH_ADC3,
	ThrR = CH_ADC1,
	ThrL = CH_ADC0
} adc_t;

void buttons_init();
bool button_is_pressed(button_t button);
uint16_t cal_adc_read(adc_t adc_val, uint16_t min, uint16_t max);

#endif /* BUTTONS_MANAGEMENT_H_ */