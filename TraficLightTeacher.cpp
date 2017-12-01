#include "TraficLightTeacher.h"

#include "cLamp.h"
#include "cTrafficLightPedestrian.h"
#include "cTrafficLightCars.h"


cLamp HeartbeatLed		(13, HIGH, LOW,  200);

cLamp lampGreenPin10	(10, HIGH, LOW,  500);
cLamp lampRedPin9		(9,  HIGH, LOW,	 500);

cLamp lampGreenPin5		(5,  LOW,  HIGH, 500);
cLamp lampRedPin4		(4,  LOW,  HIGH, 500);

cLamp lampRedPin6		(6,  HIGH, LOW,  500);
cLamp lampYellowPin7	(7,  HIGH, LOW,  500);
cLamp lampGreenPin8     (8,  HIGH, LOW,  500);

cLamp lampRedPin1		(1,  LOW,  HIGH, 500);
cLamp lampYellowPin2	(2,  LOW,  HIGH, 500);
cLamp lampGreenPin3		(3,  LOW,  HIGH, 500);



cTrafficLightPedestrian pedestrianMain(&lampGreenPin10, &lampRedPin9);

cTrafficLightPedestrian pedestrianSecondary(&lampGreenPin5, &lampRedPin4);

cTrafficLightCars		trafficLightCarsMain(&lampGreenPin8, &lampYellowPin7, &lampRedPin6);

cTrafficLightCars		trafficLightCarsSecond(&lampGreenPin3, &lampYellowPin2, &lampRedPin1);


void setup()
{
	HeartbeatLed.SetMode(lampBlink);
	pedestrianMain.SetMode(modeService);
	pedestrianMain.SetMode(modeService);
	trafficLightCarsMain.SetMode(modeService);
	trafficLightCarsSecond.SetMode(modeService);
}

// The loop function is called in an endless loop
void loop()
{
	static uint32_t saveTime = 0;
	uint32_t currentTime = millis();
	static TrafficLightModes_t trafficLightScheduler[][4] = {
			//Main Cars         Main Ped		Second Cars			Second Ped
			{modeGreen,		 	modeRed,		modeRed,			modeGreen},
			{modeGreenBlink, 	modeRed,		modeRed,			modeGreenBlink},
			{modeYellow,		modeRed,		modeRed,			modeRed},
			{modeRed, 			modeGreen,		modeRedYellow,		modeRed},
			{modeRed,			modeGreen, 		modeGreen,			modeRed},
			{modeRed,			modeGreenBlink,	modeGreenBlink,		modeRed},
			{modeRed,			modeRed,		modeRedYellow,		modeRed},
			{modeRedYellow,		modeRed,		modeRed,			modeRed}

	};
	static uint8_t currentMode = 0;

	HeartbeatLed.Run();
	pedestrianMain.Run();
	pedestrianSecondary.Run();
	trafficLightCarsMain.Run();
	trafficLightCarsSecond.Run();

	if (currentTime - saveTime > 5000){
		saveTime = millis();
		currentMode ++;
		if (currentMode > 7) currentMode = 0;
		trafficLightCarsMain.SetMode(trafficLightScheduler[currentMode][0]);
		pedestrianMain.SetMode(trafficLightScheduler[currentMode][1]);
		trafficLightCarsSecond.SetMode(trafficLightScheduler[currentMode][2]);
		pedestrianSecondary.SetMode(trafficLightScheduler[currentMode][3]);

	}
}

