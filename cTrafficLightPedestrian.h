/*
 * cTraffic;LightPedestrians.h
 *
 *  Created on: 25 םמÿב. 2017 ד.
 *      Author: ÃÏÂ
 */

#ifndef CTRAFFICLIGHTPEDESTRIANS_H_
#define CTRAFFICLIGHTPEDESTRIANS_H_

#include "cTrafficLight.h"
#include "cLamp.h"

class cTrafficLightPedestrian: public cTrafficLight {
public:
	cTrafficLightPedestrian(cLamp *ptrLampGreen, cLamp *ptrLampRed);

	void Run(void);

	void SetMode(TrafficLightModes_t newMode);

private:
	cLamp *lampGreen;
	cLamp *lampRed;

	const LampModes_t modesTable[4][2] = {
			   	   	   	   	     //Green  	Red
		/* modeGreen */			{lampOn, 	lampOff},
		/* modeGreenBlink */	{lampBlink, lampOff},
		/* modeRed */			{lampOff,	lampOn},
		/* modeService */		{lampOff,	lampOff},
	};
};

#endif /* CTRAFFICLIGHTPEDESTRIANS_H_ */
