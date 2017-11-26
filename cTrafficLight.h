/*
 * cTrafficLight.h
 *
 *  Created on: 25 םמÿב. 2017 ד.
 *      Author: ÃÏÂ
 */

#ifndef CTRAFFICLIGHT_H_
#define CTRAFFICLIGHT_H_

typedef enum{
	modeGreen,
	modeGreenBlink,
	modeRed,
	modeYellow,
	modeRedYellow
}TrafficLightModes_t;

class cTrafficLight {
public:
	virtual void Run(void);

	virtual void SetMode(TrafficLightModes_t newMode);
};

#endif /* CTRAFFICLIGHT_H_ */
