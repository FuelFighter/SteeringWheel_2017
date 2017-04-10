/*
 * can_send_status_message.c
 *
 * Created: 10.04.2017 17:39:55
 *  Author: olaliu
 */ 

#include "can_send.h"
#include "UniversalModuleDrivers/can.h"
#include "input_management.h"
#include "calibrate.h"

void can_send_status(Cvalues_struct cal_vals){
	CanMessage_t msg;
	
	msg.id = CAN_ID_STEERINGWHEEL;
	msg.length = 6;
	msg.data[0] = (uint8_t) 0; // calibrating?
	msg.data[1] = (uint8_t) ((button_is_pressed(joyButton) << 0)|(button_is_pressed(horn) << 1)|(button_is_pressed(cruiseControl) << 2)|(button_is_pressed(left) << 3)|(button_is_pressed(right) << 4)); // buttons in form: 0b00011111 if all pressed
	msg.data[2] = (uint8_t) cal_adc_read(thrL, cal_vals.minTL, cal_vals.maxTL); // uint of adc value 0-100
	msg.data[3] = (uint8_t) cal_adc_read(thrR, cal_vals.minTR, cal_vals.maxTR); // -||-
	msg.data[4] = (uint8_t) cal_adc_read(joyX, cal_vals.minJAx, cal_vals.maxJAx); // -||-
	msg.data[5] = (uint8_t) cal_adc_read(joyZ, cal_vals.minJAz, cal_vals.maxJAz); // -||-
	
	//example message [0, 0b00001000, 0, 75, 50, 50]
	
	can_send_message(&msg);
}
void can_send_calibrating(Cvalues_struct cal_vals) {
	CanMessage_t msg;
	
	msg.id = CAN_ID_STEERINGWHEEL;
	msg.length = 6;
	msg.data[0] = (uint8_t) 1; // calibrating?
	msg.data[1] = (uint8_t) ((button_is_pressed(joyButton) << 0)|(button_is_pressed(horn) << 1)|(button_is_pressed(cruiseControl) << 2)|(button_is_pressed(left) << 3)|(button_is_pressed(right) << 4)); // buttons in form: 0b00011111 if all pressed
	msg.data[2] = (uint8_t) cal_adc_read(thrL, cal_vals.minTL, cal_vals.maxTL); // uint of adc value 0-100
	msg.data[3] = (uint8_t) cal_adc_read(thrR, cal_vals.minTR, cal_vals.maxTR); // -||-
	msg.data[4] = (uint8_t) cal_adc_read(joyX, cal_vals.minJAx, cal_vals.maxJAx); // -||-
	msg.data[5] = (uint8_t) cal_adc_read(joyZ, cal_vals.minJAz, cal_vals.maxJAz); // -||-
	
	//example message [0, 0b00001000, 0, 75, 50, 50]
	
	can_send_message(&msg);
}