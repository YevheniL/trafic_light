/*
 * cTrafficLight.h
 *
 *  Created on: Nov 21, 2017
 *      Author: SAK
 */

#ifndef CTRAFFICLIGHT_H_
#define CTRAFFICLIGHT_H_

typedef enum cTrafficLightModes{
	ModeGreen,
	ModeGreenBlink,
	ModeYellow,
	ModeRed,
	ModeRedAndYellow,
	ModeAmount
};

class cTrafficLight {
public:
	virtual void Run(void);

	virtual void setMode(cTrafficLightModes newMode);
};

#endif /* CTRAFFICLIGHT_H_ */
