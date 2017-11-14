/*
 * cTrafficLight.h
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#ifndef CTRAFFICLIGHT_H_
#define CTRAFFICLIGHT_H_

#include "cLamp.h"
#include <stdint.h>
#include "stateMachine.h"

typedef enum{
	ServiceMode,
	GreenMode,
	GreenBlinkMode,
	YellowMode,
	RedMode,
	RedAndYellowMode,
	AmountModes
}cTraficLightModes;

class cTrafficLight {
public:

	/**
	 * Set mode of traffic light
	 * @param newMode - modes defined in the enum cTraficLightModes
	 * @return
	 */
	bool setMode(cTraficLightModes newMode);

	virtual void run();

protected:
	cTraficLightModes stateNew;
	cTraficLightModes stateCurrent;
	StateMachineSubStates_t stateSub;
};

#endif /* CTRAFFICLIGHT_H_ */
