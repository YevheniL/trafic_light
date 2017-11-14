/*
 * cTrafficLight.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#include "cTrafficLight.h"

bool cTrafficLight::setMode(cTraficLightModes newMode){
	if (newMode < AmountModes){
		this->stateNew = newMode;
		this->stateSub = finalization;
		return true;
	}
	else{
		return false;
	}
}

void cTrafficLight::run(){

}

