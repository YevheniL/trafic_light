/*
 * cLamp.h
 *
 *  Created on: Nov 13, 2017
 *      Author: SAK
 */

#ifndef CLAMP_H_
#define CLAMP_H_

#include <stdint.h>

class cLamp {
public:
	/**
	 * Constructor
	 * @param pin - digital output number
	 * @param levelOn - level of digital output to turn on Lamp
	 * @param levelOff - level of digital output to turn off Lamp
	 */
	void Init(uint8_t pin, uint8_t levelOn, uint8_t levelOff);

	/**
	 * Turn on lamp
	 */
	void ON(void);

	/**
	 * Turn off lamp
	 */
	void OFF(void);

	/**
	 * Switch lamp to opposite state
	 */
	void Toggle(void);

private:

	/**
	 * Current state of lamp
	 */
	bool lampState = false;

	/**
	 * Digital output number
	 */
	uint8_t pin;

	/**
	 * Level of digital output to turn ON Lamp
	 */
	uint8_t levelOn;

	/**
	 * Level of digital output to turn OFF Lamp
	 */
	uint8_t levelOff;
};

#endif /* CLAMP_H_ */
