/*
 * cCrossroadShedule.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#include "cCrossroadShedule.h"
#include "Arduino.h"

cCrossroadShedule::cCrossroadShedule(schedule_t *ptrSchedule){
	schedule = ptrSchedule;
	nSteps = schedule->scheduleStepsAmount;
//	for (uint8_t i = 0; i < schedule->scheduleStepsAmount; i++){
//		for (uint8_t j = 0; j < schedule->trafficLightsAmount; j++){
//			Serial.print(schedule->steps[i * schedule->trafficLightsAmount + j], DEC);
//			Serial.print('=');
//		}
//		Serial.print("Line \n\r");
//	}
}

uint8_t cCrossroadShedule::getState(uint8_t step, uint8_t traficLightNumber){
	if ((step < schedule->scheduleStepsAmount) && (traficLightNumber <= schedule->trafficLightsAmount)){
		return schedule->steps[step * schedule->trafficLightsAmount  + traficLightNumber];
	}
	else{
		while(1);
	}
}

