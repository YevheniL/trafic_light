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

	const uint8_t modesTable[3][2] = {
			   	   	   	   	   //Green  	Red
		/* GreenMode */		{lampOn, 	lampOff},
		/* GreenBlink */	{lampBlink, lampOff},
		/* RedMode*/		{lampOff,	lampOn}
	};
};

#endif /* CTRAFFICLIGHTPEDESTRIANS_H_ */
