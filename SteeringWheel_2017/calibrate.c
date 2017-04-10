/*
 * Calibrate.c
 *
 * Created: 05.04.2017 15:55:14
 *  Author: olaliu
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "calibrate.h"
#include "usbdb.h"
#include "UniversalModuleDrivers/adc.h"
#include "UniversalModuleDrivers/timer.h"

Cvalues_struct calibrate (void) { // 5 seconds to move the paddle-/throttles and the joystick to their max values
	Cvalues_struct cal_vals;
	cal_vals.minTL = adc_read(CH_ADC0);
	cal_vals.maxTL = adc_read(CH_ADC0);
	cal_vals.minTR = adc_read(CH_ADC1);
	cal_vals.maxTR = adc_read(CH_ADC1);
	cal_vals.minJAx = adc_read(CH_ADC2);
	cal_vals.maxJAx = adc_read(CH_ADC2);
	cal_vals.minJAz = adc_read(CH_ADC3);
	cal_vals.maxJAz = adc_read(CH_ADC3);
	
	printf("calibrating for 5 seconds...\n");
	
	timer_start(TIMER0);
	while(timer_elapsed_ms(TIMER0) < 5000) {
		uint16_t tempTL = adc_read(CH_ADC0);
		uint16_t tempTR = adc_read(CH_ADC1);
		uint16_t tempJAx = adc_read(CH_ADC2);
		uint16_t tempJAz =adc_read(CH_ADC3);
		
		if (tempTL < cal_vals.minTL) {
			cal_vals.minTL = tempTL;
		} 
		else if (tempTL > cal_vals.maxTL) {
			cal_vals.maxTL = tempTL;
		}
		
		if (tempTR < cal_vals.minTR) {
			cal_vals.minTR = tempTR;
		}
		else if (tempTR > cal_vals.maxTR) {
			cal_vals.maxTR = tempTR;
		}
		
		if (tempJAx < cal_vals.minJAx) {
			cal_vals.minJAx = tempJAx;
		}
		else if (tempJAx > cal_vals.maxJAx) {
			cal_vals.maxJAx = tempJAx;
		}
		
		if (tempJAz < cal_vals.minJAz) {
			cal_vals.minJAz = tempJAz;
		}
		else if (tempJAz > cal_vals.maxJAz) {
			cal_vals.maxJAz = tempJAz;
		}
	}
	timer_stop(TIMER0);
	if (is_calibrated_correctly(cal_vals)) { // check if values are accepted, see is_calibrated_correctly
		return cal_vals;
	} else {
		return load_calibration_values();
	}
}

Cvalues_struct load_calibration_values(void) { //load manually inserted values from previous tests
	Cvalues_struct cal_vals;
	cal_vals.minTL = 798;
	cal_vals.maxTL = 883;
	cal_vals.minTR = 812;
	cal_vals.maxTR = 894;
	cal_vals.minJAx = 0;
	cal_vals.maxJAx = 1017;
	cal_vals.minJAz = 0;
	cal_vals.maxJAz = 1023;
	return cal_vals;
}

bool is_calibrated_correctly(Cvalues_struct cal_vals) { // doesn't accept calibrate values if the difference is less than 10% of the difference in load_calibration_values()
	if ((cal_vals.maxTL - cal_vals.minTL) <= 10) {
		return false;
	} else if ((cal_vals.maxTR - cal_vals.minTR) <= 9) {
		return false;
	} else if ((cal_vals.maxJAx - cal_vals.minJAx) <= 9) {
		return false;
	} else if ((cal_vals.maxJAz - cal_vals.minJAz) <= 9) {
		return false;	
	} else {
		return true;
	}
}
