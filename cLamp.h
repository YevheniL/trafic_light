/*
 * cLamp.h
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#ifndef CLAMP_H_
#define CLAMP_H_

#include <stdint.h>

typedef enum{
	lampOn,
	lampOff,
	lampBlink
}LampModes_t;

class cLamp {
public:
	/**
	 * Constructor
	 * @param pin - digital output number
	 * @param levelOn - level of digital output to turn on Lamp
	 * @param levelOff - level of digital output to turn off Lamp
	 * @param period - period of blinking in ms. Default value is 500 ms.
	 */
	cLamp(uint8_t pin, uint8_t levelOn, uint8_t levelOff , uint16_t period = 500);

	/**
	 * Lamp state machine.
	 * Should be called periodically. At least every 100 ms.
	 */
	void Run(void);

	/**
	 * Turn ON lamp
	 */
	void ON(void);

	/**
	 * Turn OFF lamp
	 */
	void OFF(void);

	/**
	 * Switch lamp to the blink mode
	 * @param period - period of blinking in ms.
	 */
	void Blink(uint16_t period);

	/**
	 * Set mode of lamp
	 * @param newMode - One of the modes defined in the LampModes_t user type.
	 */
	void SetMode(LampModes_t newMode);


private:

	/// Digital output number
	uint8_t pin;

	 /// Level of digital output to turn ON Lamp
	uint8_t levelOn;

	/// Level of digital output to turn OFF Lamp
	uint8_t levelOff;

	/// Period of blinking
	uint16_t blinkPeriod;

	/// Blinking phase. True - lamp is ON, False - lamp is OFF.
	bool blinkState = false;

	/// Current mode of lamp
	LampModes_t mode;

	/// Time stamp which is used for blink mode
	uint32_t startTime;

	/**
	 * Turn lamp On
	 */
	void on(void);

	/**
	 * Turn lamp Off
	 */
	void off(void);
};

#endif /* CLAMP_H_ */
