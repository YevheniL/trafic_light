/*
 * cTrafficLightPedestrian.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#include "cTrafficLightPedestrian.h"
#include "Arduino.h"

cTrafficLightPedestrian::cTrafficLightPedestrian(uint8_t pinGreenLamp, uint8_t pinGreenLampLevelOn, uint8_t pinGreenLampLevelOff,
												 uint8_t pinRedLamp, uint8_t pinRedLampLevelOn, uint8_t pinRedLampLevelOff,
												 uint16_t blinkPeriod)
{
	this->greenLamp.Init(pinGreenLamp, pinGreenLampLevelOn, pinGreenLampLevelOff);
	this->redLamp.Init(pinRedLamp, pinRedLampLevelOn, pinRedLampLevelOff);
	this->blinkPeriod = blinkPeriod;
	this->stateSub = preparation;
}

void cTrafficLightPedestrian::run(){
	switch (stateCurrent){
	case GreenMode:
		stateGreen();
		break;
	case RedMode :
		stateRed();
		break;
	}
	if (stateCurrent != stateNew){
		stateCurrent = stateNew;
	}
}

void cTrafficLightPedestrian::stateGreen(){
	switch (stateSub){
	case preparation :
		stateSub = execution;
		greenLamp.ON();
		break;
	case execution :
		break;
	case finalization :
		stateSub = preparation;
		greenLamp.OFF();
		break;
	default:
		stateSub = preparation; // exeqution
	}
}

void cTrafficLightPedestrian::stateRed(){
	switch (stateSub){
	case preparation :
		stateSub = execution;
		redLamp.ON();
		break;
	case execution :
		break;
	case finalization :
		stateSub = preparation;
		stateCurrent = stateNew;
		redLamp.OFF();
		break;
	default:
		stateSub = preparation;
	}
}


