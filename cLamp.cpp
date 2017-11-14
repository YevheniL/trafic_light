/*
 * cLamp.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#include "cLamp.h"
#include "Arduino.h"

void cLamp::Init(uint8_t pin, uint8_t levelOn, uint8_t levelOff) {
	this->pin = pin;
	this->levelOn = levelOn;
	this->levelOff = levelOff;
	pinMode(this->pin, OUTPUT);
	this->OFF();
}

void cLamp::ON(void) {
	digitalWrite(pin, levelOn);
	lampState = true;
}

void cLamp::OFF(void) {
	digitalWrite(pin, levelOff);
	lampState = false;
}

void cLamp::Toggle(void) {

	lampState = !lampState;
	if (lampState){
		ON();
	}
	else{
		OFF();
	}
}

