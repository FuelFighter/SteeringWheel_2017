/*
 * calibrate.h
 *
 * Created: 05.04.2017 15:55:34
 *  Author: olaliu
 */ 


#ifndef CALIBRATE_H_
#define CALIBRATE_H_

typedef struct {
	uint16_t minTL;
	uint16_t maxTL;
	uint16_t minTR;
	uint16_t maxTR;
	uint16_t minJAx;
	uint16_t maxJAx;
	uint16_t minJAz;
	uint16_t maxJAz;
} Cvalues_struct ;

Cvalues_struct calibrate(void);
Cvalues_struct load_calibration_values(void);
bool is_calibrated_correctly(Cvalues_struct cal_vals);

#endif /* CALIBRATE_H_ */