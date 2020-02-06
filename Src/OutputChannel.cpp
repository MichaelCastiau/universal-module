/*
 * OutputChannel.cpp
 *
 *  Created on: Jan 21, 2020
 *      Author: michael
 */

#include "OutputChannel.h"

OutputChannel::OutputChannel(GPIO_TypeDef *port, uint16_t pin) {
	this->port = port;
	this->pin = pin;

}

OutputChannel::~OutputChannel() {
	// TODO Auto-generated destructor stub
}

void OutputChannel::toggle() {
	HAL_GPIO_TogglePin(this->port, this->pin);
}

void OutputChannel::turnOn() {
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);
}
void OutputChannel::turnOff() {
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);
}
