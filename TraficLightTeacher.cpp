#include "TraficLightTeacher.h"

#include "cLamp.h"

cLamp HeartbeatLed(13, HIGH, LOW, 200);

cLamp YellowLed1(7, HIGH, LOW, 500);

cLamp YellowLed2(2, LOW, HIGH, 500);

//The setup function is called once at startup of the sketch
void setup()
{
	HeartbeatLed.SetMode(lampBlink);

	YellowLed1.SetMode(lampBlink);

	YellowLed2.SetMode(lampBlink);
}

// The loop function is called in an endless loop
void loop()
{
	HeartbeatLed.Run();
	YellowLed1.Run();
	YellowLed2.Run();
}

