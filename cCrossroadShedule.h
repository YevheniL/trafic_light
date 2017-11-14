/*
 * cCrossroadShedule.h
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#ifndef CCROSSROADSHEDULE_H_
#define CCROSSROADSHEDULE_H_

#include <stdint.h>

typedef struct{
	uint8_t trafficLightsAmount;
	uint8_t scheduleStepsAmount;
	uint8_t *steps;
}schedule_t;

class cCrossroadShedule {
public:
	uint8_t nSteps;

	cCrossroadShedule(schedule_t *ptrSchedule);
	uint8_t getState(uint8_t step, uint8_t traficLightNumber);

private:
	schedule_t *schedule;
};

#endif /* CCROSSROADSHEDULE_H_ */
