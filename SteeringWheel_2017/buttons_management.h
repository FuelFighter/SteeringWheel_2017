/*
 * buttons_management.h
 *
 * Created: 04.04.2017 16:55:26
 *  Author: ola
 */ 


#ifndef BUTTONS_MANAGEMENT_H_
#define BUTTONS_MANAGEMENT_H_
#include <stdbool.h>

typedef enum {
	JoyButton = PINB0,
	Horn = PINB1,
	CruiseControl = PINB2,
	Left = PINB3,
	Right = PINB4
} button_t;

void buttons_init();
bool button_is_pressed(button_t button);

#endif /* BUTTONS_MANAGEMENT_H_ */