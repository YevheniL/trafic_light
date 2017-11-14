/*
 * cTrafficLightPedestrian.h
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#ifndef CTRAFFICLIGHTPEDESTRIAN_H_
#define CTRAFFICLIGHTPEDESTRIAN_H_

#include "cTrafficLight.h"
#include <stdint.h>

class cTrafficLightPedestrian: private cTrafficLight {
public:
	cTrafficLightPedestrian(uint8_t pinGreenLamp, uint8_t pinGreenLampLevelOn, uint8_t pinGreenLampLevelOff,
							uint8_t pinRedLamp, uint8_t pinRedLampLevelOn, uint8_t pinRedLampLevelOff,
							uint16_t blinkPeriod
							);
	void run();

private:
	cLamp redLamp;
	cLamp greenLamp;
	uint16_t blinkPeriod;

	void stateGreen();

	void stateRed();
};

#endif /* CTRAFFICLIGHTPEDESTRIAN_H_ */
