/*
 * SteeringWheel_2017.c
 *
 * Created: 18/03/17 15:13:44
 * Author : Sondre
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "usbdb.h"
#include "UniversalModuleDrivers/adc.h"
#include "buttons_management.h"
#include "calibrate.h"
#include "UniversalModuleDrivers/timer.h"

int main(void)
{	
	usbdbg_init();	//init usb communication
	adc_init();		//init adc
	buttons_init();	//init buttons
	timer_init();	//init timer
	
	// calibrate();	//calibrate joystick, and throttles
	while (1) {
		printf("Horn: %d\nJoyB: %d\nCCon: %d\nRigh: %d\nLeft: %d\n",button_is_pressed(Horn), button_is_pressed(JoyButton),button_is_pressed(CruiseControl),button_is_pressed(Right),button_is_pressed(Left));
		printf("ThrL: %u \n",adc_read(CH_ADC0));
		printf("ThrR: %u \n",adc_read(CH_ADC1));
		printf("JoyX: %u \n",adc_read(CH_ADC2));
		printf("JoyY: %u \n",adc_read(CH_ADC3));
		printf("\n");
		_delay_ms(50);
	}
}
