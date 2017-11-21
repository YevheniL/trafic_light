/*
 * cLamp.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#include "cLamp.h"
#include "Arduino.h"

cLamp::cLamp(uint8_t pin, uint8_t levelOn, uint8_t levelOff, uint16_t period) {
	this->pin = pin;
	this->levelOn = levelOn;
	this->levelOff = levelOff;
	this->blinkPeriod = period;
	pinMode(this->pin, OUTPUT);
	this->mode = lampOff;
	this->off();
	startTime = millis();
}

void cLamp::Run(){
	if (mode == lampBlink) {
		uint32_t currentTime = millis();
		if (currentTime - startTime > blinkPeriod){
			if (blinkState){
				on();
			}
			else{
				off();
			}
			blinkState = !blinkState;
			startTime = millis();
		}
	}
}

void cLamp::ON(void) {
	mode = lampOn;
	on();
}

void cLamp::OFF(void) {
	mode = lampOff;
	off();
}


void cLamp::Blink(uint16_t period) {
	blinkPeriod = period;
	SetMode(lampBlink);
}

void cLamp::SetMode(LampModes_t newMode){
	mode = newMode;
	startTime = millis();
}

void cLamp::on(void) {
	digitalWrite(pin, levelOn);
}

void cLamp::off(void) {
	digitalWrite(pin, levelOff);
}



