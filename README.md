
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

Before using this library, initialize it. Initializing the module will set the needed configuration to GPIO pins for correct mapping of the output channels.
Aditionally, the 6 output channels will be created and are available for use in your application.

```c++
#include <UniversalModule.cpp>

initializeUniversalModule();

channel1.turnOn();

#define BATHROOM channel2;
BATHROOM.turnOff();
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
