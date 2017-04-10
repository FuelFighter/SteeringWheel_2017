/*
 * SteeringWheel_2017.c
 *
 * Created: 18/03/17 15:13:44
 * Author : Sondre
 */ 

#define F_CPU 8000000UL
#define car_moving true
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
	
	Cvalues_struct cal_vals = load_calibration_values();	//calibrate joystick, and throttle
	int buttons[9];
	
	while (1) {
		buttons[0] = button_is_pressed(joyButton);
		buttons[1] = button_is_pressed(horn);
		buttons[2] = button_is_pressed(cruiseControl);
		buttons[3] = button_is_pressed(left);
		buttons[4] = button_is_pressed(right);
		buttons[5] = cal_adc_read(thrL, cal_vals.minTL, cal_vals.maxTL);
		buttons[6] = 100 - cal_adc_read(thrR, cal_vals.minTR, cal_vals.maxTR);
		buttons[7] = cal_adc_read(joyZ, cal_vals.minJAz, cal_vals.maxJAz);
		buttons[8] = 100 - cal_adc_read(joyX, cal_vals.minJAx, cal_vals.maxJAx);
		if(buttons[0] && buttons[3] && !car_moving) { //TODO can't calibrate while vehicle is moving
			//TODO? Send can frame saying its calibrating
			cal_vals = calibrate();
		}
		printf("JoyB: %d\nHorn: %d\nCCon: %d\nLeft: %d\nRigh: %d\n",buttons[0], buttons[1], buttons[2], buttons[3], buttons[4]);
		printf("ThrL: %d\nThrR: %d\nJoyZ: %d\nJoyX: %d\n",buttons[5], buttons[6], buttons[7], buttons[8]);
		_delay_ms(50);
	}
}
