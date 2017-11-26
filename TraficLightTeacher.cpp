#include "TraficLightTeacher.h"

#include "cLamp.h"
#include "cTrafficLightPedestrian.h"

cLamp HeartbeatLed(13, HIGH, LOW, 200);

cLamp lampGreen10(10, HIGH, LOW, 500);
cLamp lampRed9(9, HIGH, LOW, 500);

cLamp lampGreen5(5, LOW, HIGH, 500);
cLamp lampRed4(4, LOW, HIGH, 500);


cTrafficLightPedestrian pedestrianMain(&lampGreen10, &lampRed9);
cTrafficLightPedestrian pedestrianSecondary(&lampGreen5, &lampRed4);

//The setup function is called once at startup of the sketch
void setup()
{
	HeartbeatLed.SetMode(lampBlink);
	pedestrianMain.SetMode(modeGreen);
	pedestrianMain.SetMode(modeRed);
}

// The loop function is called in an endless loop
void loop()
{
	static uint32_t saveTime = 0;
	uint32_t currentTime = millis();
	static TrafficLightModes_t trafficLightScheduler[][2] = {
			{modeGreen,		 	modeRed},
			{modeGreenBlink, 	modeRed},
			{modeRed, 			modeGreen},
			{modeRed,			modeGreenBlink},
	};
	static uint8_t currentMode = 0;

	HeartbeatLed.Run();
	pedestrianMain.Run();
	pedestrianSecondary.Run();

	if (currentTime - saveTime > 5000){
		saveTime = millis();
		currentMode ++;
		if (currentMode > 3) currentMode = 0;
		pedestrianMain.SetMode(trafficLightScheduler[currentMode][0]);
		pedestrianSecondary.SetMode(trafficLightScheduler[currentMode][1]);
	}
}

