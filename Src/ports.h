#include <stdint.h>
#include "stm32f0xx_hal.h"
#include "OutputChannel.h"
/*
 * ports.h
 *
 *  Created on: Jan 21, 2020
 *      Author: michael
 */

#ifndef INC_PORTS_H_
#define INC_PORTS_H_

/**
 * Channels as they are defined in hardware
 * Channels are active high
 */
#define CHANNEL_1_PORT GPIOB
#define CHANNEL_1_PIN  GPIO_PIN_14
#define CHANNEL_2_PORT GPIOB
#define CHANNEL_2_PIN  GPIO_PIN_15
#define CHANNEL_3_PORT GPIOA
#define CHANNEL_3_PIN  GPIO_PIN_8
#define CHANNEL_4_PORT GPIOA
#define CHANNEL_4_PIN  GPIO_PIN_9
#define CHANNEL_5_PORT GPIOA
#define CHANNEL_5_PIN  GPIO_PIN_10
#define CHANNEL_6_PORT GPIOA
#define CHANNEL_6_PIN  GPIO_PIN_11

extern OutputChannel channel1(CHANNEL_1_PORT, CHANNEL_1_PIN);
extern OutputChannel channel2(CHANNEL_2_PORT, CHANNEL_2_PIN);
extern OutputChannel channel3(CHANNEL_3_PORT, CHANNEL_3_PIN);
extern OutputChannel channel4(CHANNEL_4_PORT, CHANNEL_4_PIN);
extern OutputChannel channel5(CHANNEL_5_PORT, CHANNEL_5_PIN);
extern OutputChannel channel6(CHANNEL_6_PORT, CHANNEL_6_PIN);

#define CHANNEL1 channel1
#define CHANNEL2 channel2
#define CHANNEL3 channel3
#define CHANNEL4 channel4
#define CHANNEL5 channel5
#define CHANNEL6 channel6

#endif /* INC_PORTS_H_ */
