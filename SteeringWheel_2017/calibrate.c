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

void calibrate (void) {
	uint16_t minTL = adc_read(CH_ADC0);
	uint16_t maxTL = adc_read(CH_ADC0);
	uint16_t minTR = adc_read(CH_ADC1);
	uint16_t maxTR = adc_read(CH_ADC1);
	uint16_t minJAx = adc_read(CH_ADC2);
	uint16_t maxJAx = adc_read(CH_ADC2);
	uint16_t minJAz = adc_read(CH_ADC3);
	uint16_t maxJAz = adc_read(CH_ADC3);
	
	printf("calibrating for 3 seconds");
	timer_start(TIMER0);
	while(timer_elapsed_ms(TIMER0) < 3000) {
		uint16_t tempTL = adc_read(CH_ADC0);
		uint16_t tempTR = adc_read(CH_ADC1);
		uint16_t tempJAx = adc_read(CH_ADC2);
		uint16_t tempJAz =adc_read(CH_ADC3);
		
		if (tempTL < minTL) {
			minTL = tempTL;
		} 
		else if (tempTL > maxTL) {
			maxTL = tempTL;
		}
		
		if (tempTR < minTR) {
			minTR = tempTR;
		}
		else if (tempTR > maxTR) {
			maxTR = tempTR;
		}
		
		if (tempJAx < minJAx) {
			minJAx = tempJAx;
		}
		else if (tempJAx > maxJAx) {
			maxJAx = tempJAx;
		}
		
		if (tempJAz < minJAz) {
			minJAz = tempJAz;
		}
		else if (tempJAz > maxJAz) {
			maxJAz = tempJAz;
		}
	}
	timer_stop(TIMER0);
	printf("calibration complete");
	
	printf("minTL,maxTL: %u, %u\n", minTL,maxTL);
	printf("minTR,maxTR: %u, %u\n", minTR,maxTR);
	printf("minJAx,maxJAx: %u, %u\n", minJAx,maxJAx);
	printf("minJAz,maxJAz: %u, %u\n", minJAz,maxJAz);
}