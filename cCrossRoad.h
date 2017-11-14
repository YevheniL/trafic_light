/*
 * cCrossRoad.h
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#ifndef CCROSSROAD_H_
#define CCROSSROAD_H_

#include <stdint.h>
#include "cTrafficLight.h"
#include "cCrossroadShedule.h"

class cCrossRoad {
public:
	cCrossRoad(cTrafficLight **ptrTrafficLightsList, uint8_t trafficLightsAmount, cCrossroadShedule *ptrSchedule);

	void run();
private:
	cCrossroadShedule *Schedule;
	cTrafficLight **TrafficLightsList;
	uint8_t trafficLightsAmount;
	uint32_t stepSaveTime;
	uint8_t step;
};

#endif /* CCROSSROAD_H_ */
