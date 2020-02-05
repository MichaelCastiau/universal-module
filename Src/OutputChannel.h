#include <stdint.h>
#include "stm32f0xx_hal.h"
/*
 * OutputChannel.h
 *
 *  Created on: Jan 21, 2020
 *      Author: michael
 */

#ifndef MODELS_OUTPUTCHANNEL_H_
#define MODELS_OUTPUTCHANNEL_H_

class OutputChannel {
private:
	GPIO_TypeDef *port;
	uint16_t pin;
public:
	OutputChannel(GPIO_TypeDef *port, uint16_t pin);
	virtual ~OutputChannel();

	void turnOn();
	void turnOff();
};

#endif /* MODELS_OUTPUTCHANNEL_H_ */
