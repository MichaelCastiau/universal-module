
# Universal Module for Railroad Model interaction Library

This project is a C library that can be used to run an Universal Module (schematics designed by @Michael Castiau).
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

Before using this library, initialize it.

````c
#include <UniversalModule.c> 
````