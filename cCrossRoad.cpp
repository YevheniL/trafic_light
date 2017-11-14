/*
 * cCrossRoad.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#include "cCrossRoad.h"
#include "Arduino.h"

cCrossRoad::cCrossRoad(cTrafficLight **ptrTrafficLightsList, uint8_t trafficLightsAmount, cCrossroadShedule *ptrSchedule){
	this->TrafficLightsList = ptrTrafficLightsList;
	this->trafficLightsAmount = trafficLightsAmount;
	this->Schedule = ptrSchedule;
	this->stepSaveTime = millis();
	this->step = 0;
}

void cCrossRoad::run(){
	uint32_t currentTime = millis();
	uint32_t stepDuration = 1000 * Schedule->getState(step, 0);
	if (currentTime - stepSaveTime > stepDuration){
		step = step + 1;
		if (step >= Schedule->nSteps){
			step = 0;
		}
		Serial.print("Step: ");
		Serial.print(step);
		Serial.print(" nStep: ");
		Serial.print(Schedule->nSteps);
		Serial.print(" StepDuration: ");
		stepDuration = 1000 * Schedule->getState(step, 0);
		Serial.print(stepDuration);

		for (uint8_t i = 0; i < trafficLightsAmount; i++){
			cTraficLightModes newMode = Schedule->getState(step, i+1);
			TrafficLightsList[i]->setMode(newMode);
			Serial.print(" mode: ");
			Serial.print(newMode);
		}
		Serial.print(" *\r\n");
		stepSaveTime = millis();
	}

	for(uint8_t i = 0; i < trafficLightsAmount; i++){
		TrafficLightsList[i]->run();
	}
}
