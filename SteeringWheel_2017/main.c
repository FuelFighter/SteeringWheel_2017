/*
 * SteeringWheel_2017.c
 *
 * Created: 18/03/17 15:13:44
 * Author : Sondre
 */ 

#include <avr/io.h>
#include "usbdb.h"
#include <util/delay.h>
#include "UniversalModuleDrivers/adc.h"
#include "buttons_management.h"

int main(void)
{	
	usbdbg_init();
	adc_init();
	buttons_init();
	
	while (1)
	{
		printf("Horn: %d\nJoyB: %d\nCCon: %d\nRigh: %d\nLeft: %d\n",button_is_pressed(Horn), button_is_pressed(JoyButton),button_is_pressed(CruiseControl),button_is_pressed(Right),button_is_pressed(Left));
		printf("ThrL: %u \n",adc_read(CH_ADC0));
		printf("ThrR: %u \n",adc_read(CH_ADC1));
		printf("JoyX: %u \n",adc_read(CH_ADC2));
		printf("JoyY: %u \n",adc_read(CH_ADC3));
		printf("\n");
		_delay_ms(50);
	}
}
