#include "TraficLightTeacher.h"

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

#define TRAFFIC_LIGHT_MODE_TIME_SERVICE		10		/// Service mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_GREEN		6		///	Green mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_GREEN_BLINK	3		/// Green blink mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_YELLOW		3		/// Yellow mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_RED			6		/// Red mode duration in seconds
#define TRAFFIC_LIGHT_MODE_TIME_RED_YELOW	3		/// Red and yellow mode duration in seconds

#define DELAY_HALF_SECOND		500

bool isServiceMode = true;

/**
 * The Service mode of traffic light. Yellow lamp is blinking with period 1 second during a time defined in the parameter time.
 * @param time - mode duration in seconds.
 */
void TrafficLight_ModeService(unsigned short time);

/**
 * The Red mode of traffic light. The red lamp is lighting constantly during a time defined in the parameter time.
 * @param time - mode duration in seconds.
 */
void TrafficLight_ModeRed(unsigned short time);

/**
 * The Red plus Yellow safety mode of traffic light. Red and Yellow lamps are lighting constantly during a time defined in the parameter time.
 * @param time - mode duration in seconds.
 */
void TrafficLight_ModeRedAndYellow(unsigned short time);

/**
 * The Green mode of traffic light. The red lamp is lighting constantly during a time defined in the parameter time.
 * @param time - mode duration in seconds.
 */
void TrafficLight_ModeGreen(unsigned short time);

/**
 * The Green Blink mode of traffic light. The green lamp is blinking with period 1 second during a time defined in the parameter time.
 * @param time - mode duration in seconds.
 */
void TrafficLight_ModeGreenBlink(unsigned short time);

/**
 * The Yellow mode of traffic light. The yellow lamp is lighting constantly during a time defined in the parameter time.
 * @param time - mode duration in seconds.
 */
void TrafficLight_ModeYellow(unsigned short time);

/**
 * Turn off all lamps of traffic light
 */
void TrafficLight_AllLampsOff(void);

/**
 * Delay and heartbeat function. Function adds delay to program. Heartbeat LED is blinking with period 0.5 seconds during pause.
 * @param time - delay duration in seconds
 */
void DelayAndHeartbeat(unsigned short time);



//The setup function is called once at startup of the sketch
void setup()
{
	// Outputs initialization
	pinMode(HEARTBEAT_LED, OUTPUT);
	pinMode(TRAFFIC_LIGHT_CARS_RED_LAMP, OUTPUT);
	pinMode(TRAFFIC_LIGHT_CARS_YELLOW_LAMP, OUTPUT);
	pinMode(TRAFFIC_LIGHT_CARS_GREEN_LAMP, OUTPUT);
	pinMode(TRAFFIC_LIGHT_PEDESTRIAN_RED_LAMP, OUTPUT);
	pinMode(TRAFFIC_LIGHT_PEDESTRIAN_GREEN_LAMP, OUTPUT);

	// Outputs safety states write
	digitalWrite(HEARTBEAT_LED, HEARTBEAT_LED_OFF);
	TrafficLight_AllLampsOff();
}

// The loop function is called in an endless loop
void loop()
{
	if (isServiceMode){
		TrafficLight_ModeService(TRAFFIC_LIGHT_MODE_TIME_SERVICE);
		isServiceMode = false;
	}
	else{
		TrafficLight_ModeGreen(TRAFFIC_LIGHT_MODE_TIME_GREEN);
		TrafficLight_ModeGreenBlink(TRAFFIC_LIGHT_MODE_TIME_GREEN_BLINK);
		TrafficLight_ModeYellow(TRAFFIC_LIGHT_MODE_TIME_YELLOW);
		TrafficLight_ModeRed(TRAFFIC_LIGHT_MODE_TIME_RED);
		TrafficLight_ModeRedAndYellow(TRAFFIC_LIGHT_MODE_TIME_RED_YELOW);
	}
}

void TrafficLight_ModeService(unsigned short time){

	TrafficLight_AllLampsOff();

	for (unsigned short seconds = 0; seconds < time; seconds ++){
		digitalWrite(TRAFFIC_LIGHT_CARS_YELLOW_LAMP, TRAFFIC_LIGHT_LAMP_ON);
		DelayAndHeartbeat(1);
		digitalWrite(TRAFFIC_LIGHT_CARS_YELLOW_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
		DelayAndHeartbeat(1);
	}
}

void TrafficLight_ModeRed(unsigned short time){
	TrafficLight_AllLampsOff();

	digitalWrite(TRAFFIC_LIGHT_CARS_RED_LAMP, TRAFFIC_LIGHT_LAMP_ON);
	DelayAndHeartbeat(time * 2);
}

void TrafficLight_ModeRedAndYellow(unsigned short time){
	TrafficLight_AllLampsOff();

	digitalWrite(TRAFFIC_LIGHT_CARS_RED_LAMP, TRAFFIC_LIGHT_LAMP_ON);
	digitalWrite(TRAFFIC_LIGHT_CARS_YELLOW_LAMP, TRAFFIC_LIGHT_LAMP_ON);
	DelayAndHeartbeat(time);
}

void TrafficLight_ModeGreen(unsigned short time){
	TrafficLight_AllLampsOff();

	digitalWrite(TRAFFIC_LIGHT_CARS_GREEN_LAMP, TRAFFIC_LIGHT_LAMP_ON);
	DelayAndHeartbeat(time);
}

void TrafficLight_ModeGreenBlink(unsigned short time){
	TrafficLight_AllLampsOff();

	for (unsigned short seconds = 0; seconds < time; seconds ++){
		digitalWrite(TRAFFIC_LIGHT_CARS_GREEN_LAMP, TRAFFIC_LIGHT_LAMP_ON);
		DelayAndHeartbeat(1);
		digitalWrite(TRAFFIC_LIGHT_CARS_GREEN_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
		DelayAndHeartbeat(1);
	}
}

void TrafficLight_ModeYellow(unsigned short time){
	TrafficLight_AllLampsOff();

	digitalWrite(TRAFFIC_LIGHT_CARS_YELLOW_LAMP, TRAFFIC_LIGHT_LAMP_ON);
	DelayAndHeartbeat(time);
}

void TrafficLight_AllLampsOff(void){
	digitalWrite(TRAFFIC_LIGHT_CARS_RED_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
	digitalWrite(TRAFFIC_LIGHT_CARS_YELLOW_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
	digitalWrite(TRAFFIC_LIGHT_CARS_GREEN_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
	digitalWrite(TRAFFIC_LIGHT_PEDESTRIAN_RED_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
	digitalWrite(TRAFFIC_LIGHT_PEDESTRIAN_GREEN_LAMP, TRAFFIC_LIGHT_LAMP_OFF);
}

void DelayAndHeartbeat(unsigned short time){
	static bool heartbeatState = false;

	for (unsigned short seconds = 0; seconds < (time); seconds ++){
		delay(DELAY_HALF_SECOND);
		heartbeatState = !heartbeatState;
		if (heartbeatState){
			digitalWrite(HEARTBEAT_LED, HEARTBEAT_LED_ON);
		}
		else{
			digitalWrite(HEARTBEAT_LED, HEARTBEAT_LED_OFF);
		}
	}
}
