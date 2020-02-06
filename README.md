
# Universal Module for Railroad Model interaction Library

This project is a C++ library that can be used to run an Universal Module (schematics designed by @Michael Castiau).
The library is C++11 standard compliant.
These modules are able to run up to 6 ports with 250mA, enabling switching different model railroad items such as lights, smoke generators,
digital interfaces, ...

The module may also interface with 4 function input pins, enabling programming sequence hooks to those inputs. 

The source code included into this project is supposed to be modular and generic, making it adaptable for many different applications.

## Hardware

Key hardware features:
- STM32F0306
- Toshiba 500mA Darlington Array driver

Input: 12-18V max. 0.5A
Output/channel: 12-18V max. current: (500mA / #Used channels) and max. 250mA

## Usage

### Hardware Initialization

Before using the library, initialize following pins as GPIO outputs (push-pull):

- PA8
- PA9
- PA10
- PA11
- PB14
- PB15

Additionally, a timer may be required to call the `tick()` method periodically. It is advised to use the timer in Interrupt or DMA mode:

```c++ main.cpp
HAL_TIM_Base_Start_IT(/*timer reference*/);

void TIM14_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim14);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    sequence.tick();    //You need to periodically call this method
}
```

### Channels

Channel objects represent the real wold, 6 channels that are present on the hardware. You may turn them on and off respectively by using:
```c++
channel1.turnOn();
channel1.turnOff();
```
The naming of the channels is respectively: `channel[n]` with `n = 1...6`.

### AnimationFrames

An animation frame is an action that the module can execute, essentially being a callback.

```c++
AnimationFrame turnOnBathroom([]{
    channel1.turnOn();
});
```

### AnimationSequence

Frames may be added to an animation sequence. Once the sequence is started, the sequence will loop through the frames, animating the module as programmed.

```c++
AnimationSequence sequence;
sequence.addFrame(10, &turnOnBathroom);
sequence.addFrame(60, &turnOffBathroom);

sequence.start();

// In a timer loop, for example ever second
callbackSecond() {
    sequence.tick();
}
```
