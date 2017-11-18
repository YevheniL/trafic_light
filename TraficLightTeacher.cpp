#include "TraficLightTeacher.h"

#include "cCrossRoad.h"
#include "cCrossroadShedule.h"
#include "cTrafficLight.h"
#include "cTrafficLightPedestrian.h"


#define TRAFFIC_LIGHT_CARS_RED_LAMP			6		/// Digital output pin number for the traffic light red lamp for cars
#define TRAFFIC_LIGHT_CARS_YELLOW_LAMP		5		/// Digital output pin number for the traffic light yellow lamp for cars
#define TRAFFIC_LIGHT_CARS_GREEN_LAMP		4		/// Digital output pin number for the traffic light green lamp for cars
#define TRAFFIC_LIGHT_PEDESTRIAN_RED_LAMP	3		/// Digital output pin number for the traffic light red lamp for pedestrian
#define TRAFFIC_LIGHT_PEDESTRIAN_GREEN_LAMP	2		/// Digital output pin number for the traffic light green lamp for pedestrian

#define HEARTBEAT_LED	13		/// Digital output pin number for the heartbeat LED

#define TRAFFIC_LIGHT_LAMP_ON	LOW		/// Traffic Light lamp pin active level
#define TRAFFIC_LIGHT_LAMP_OFF	HIGH	/// Traffic Light lamp pin not active level

#define HEARTBEAT_LED_ON	HIGH		/// Heartbeat LED pin active level
#define HEARTBEAT_LED_OFF	LOW			///	Heartbeat LED pin not active level
#define HEARTBEAT_PERIOD 	500			/// heartbeat period = 500

#define TRAFFIC_LIGHT_MODE_TIME_SERVICE		10		/// Service mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_GREEN		6		///	Green mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_GREEN_BLINK	3		/// Green blink mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_YELLOW		3		/// Yellow mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_RED			6		/// Red mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_RED_YELOW	3		/// Red and yellow mode duration in seconds

#define DELAY_HALF_SECOND		500

#define TRAFFIC_LIGHTS_AMAUNT	2
#define CROSSROAD_STEPS_AMOUNT	4

void Heartbeat_Run( unsigned int period );

uint8_t steps[CROSSROAD_STEPS_AMOUNT][TRAFFIC_LIGHTS_AMAUNT+1] = {
//StepTime  |  Pedesrian_M   |	Pedesrian_S
	{5, 	RedMode,	GreenMode		},
	{5,		GreenMode,	RedMode			},
	{10,	RedMode,	RedMode			},
	{15,	GreenMode,	GreenMode		},
};

schedule_t schedule = {
		(TRAFFIC_LIGHTS_AMAUNT+1),
		CROSSROAD_STEPS_AMOUNT,
		&steps[0][0]
};

cCrossroadShedule crossroadSchedule(&schedule);

cTrafficLightPedestrian TrafficLightPedestrianMain	(10, HIGH, LOW,  9, HIGH, LOW,  500);
cTrafficLightPedestrian TrafficLightPedestrianSecond( 5, LOW,  HIGH, 4, LOW,  HIGH, 500);


cTrafficLight *trafficLightsList[] = {
		(cTrafficLight *)&TrafficLightPedestrianMain,
	    (cTrafficLight *)&TrafficLightPedestrianSecond
};


cCrossRoad CrossRoad(trafficLightsList, TRAFFIC_LIGHTS_AMAUNT, &crossroadSchedule);

//The setup function is called once at startup of the sketch
void setup()
{
	// Outputs initialization
	pinMode(HEARTBEAT_LED, OUTPUT);

	// Outputs safety states write
	digitalWrite(HEARTBEAT_LED, HEARTBEAT_LED_OFF);

	Serial.begin(115200);
}

// The loop function is called in an endless loop
void loop()
{
	Heartbeat_Run( HEARTBEAT_PERIOD );
	CrossRoad.run();
}

void Heartbeat_Run( unsigned int period ){
	static unsigned int saveTime = 0;
	unsigned int currentTime = 0;
	static bool state = false;

	currentTime = millis();
	if ((currentTime - saveTime) >= period) {
		if (state) {
			digitalWrite( HEARTBEAT_LED, HEARTBEAT_LED_ON);
		} else {
			digitalWrite( HEARTBEAT_LED, HEARTBEAT_LED_OFF);
		}
		state = !state;
		saveTime = millis();
	}
}

