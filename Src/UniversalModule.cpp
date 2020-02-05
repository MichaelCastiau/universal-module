/**
 ******************************************************************************
 * @file     lib.c
 * @author   Auto-generated by STM32CubeIDE
 * @version  V1.0
 * @date     04/02/2020 20:08:22
 * @brief    Default under dev library file.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/

#include "AnimationSequence.h"
#include "AnimationFrame.h"
#include "ports.h"
#include "gpio_configuration.cpp"

/**
 * Initializes the use of this library
 * by setting the correct GPIO pins configuration.
 * Call this method after initializing the clock and general
 * settings in your embedded system code.
 */
void initializeModule(void) {
	initializeGPIOPins();
}
