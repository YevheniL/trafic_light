/*
 * cTrafficLightCars.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: SAK
 */

#include "cTrafficLightCars.h"

cTrafficLightCars::cTrafficLightCars(cLamp *ptrLampGreen, cLamp *ptrLampYellow, cLamp *ptrLampRed) {
	this->lampGreen 	= ptrLampGreen;
	this->lampYellow 	= ptrLampYellow;
	this->lampRed 		= ptrLampRed;
}

void cTrafficLightCars::Run(void){
	lampGreen->Run();
	lampYellow->Run();
	lampRed->Run();
}

void cTrafficLightCars::SetMode(TrafficLightModes_t newMode){
	lampGreen->SetMode((LampModes_t)modesTable[newMode][0]);
	lampYellow->SetMode((LampModes_t)modesTable[newMode][1]);
	lampRed->SetMode((LampModes_t)modesTable[newMode][2]);
}

