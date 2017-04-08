/*
 * SteeringWheel_2017.c
 *
 * Created: 18/03/17 15:13:44
 * Author : Sondre
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usbdb.h"
#include "UniversalModuleDrivers/adc.h"
#include "input_management.h"
#include "calibrate.h"
#include "UniversalModuleDrivers/timer.h"

int main(void)
{	
	usbdbg_init();	//init usb communication
	adc_init();		//init adc
	buttons_init();	//init buttons
	timer_init();	//init timer
	sei();
	
	Cvalues_struct cal_vals = calibrate();	//calibrate joystick, and throttles
	while (1) {
		printf("Horn: %d\nJoyB: %d\nCCon: %d\nRigh: %d\nLeft: %d\n",button_is_pressed(Horn), button_is_pressed(JoyButton),button_is_pressed(CruiseControl),button_is_pressed(Right),button_is_pressed(Left));
		printf("ThrL: %u\n",cal_adc_read(ThrL, cal_vals.minTL, cal_vals.maxTL));
		printf("ThrR: %u\n",100 - cal_adc_read(ThrR, cal_vals.minTR, cal_vals.maxTR));
		printf("JoyX: %u\n",100 - cal_adc_read(JoyX, cal_vals.minJAx, cal_vals.maxJAx));
		printf("JoyY: %u\n",cal_adc_read(JoyZ, cal_vals.minJAz, cal_vals.maxJAz));
		printf("\n");
		_delay_ms(50);
	}
}
