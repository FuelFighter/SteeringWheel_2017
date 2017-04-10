/*
 * can_send_status_message.h
 *
 * Created: 10.04.2017 17:40:23
 *  Author: olaliu
 */ 


#ifndef CAN_SEND_STATUS_MESSAGE_H_
#define CAN_SEND_STATUS_MESSAGE_H_
#define CAN_ID_STEERINGWHEEL 0x20 //intill videre
#include "calibrate.h"

void can_send_status(Cvalues_struct cal_vals);
void can_send_calibrating(Cvalues_struct cal_vals);

#endif /* CAN_SEND_STATUS_MESSAGE_H_ */