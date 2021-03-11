## Introduction

TahakomAVRLib is a C++ library to program Atmel AVR Microcontrollers. 
The library make use of the AVR standard C library and is written for easy usage.

Currently, the classes compile on the ATmega48P/88P/168P/328P AVR Microcontrollers family. 


## Library structure 

The library is composed of several classes that abstract the different elements that compose a Microcontroller. 
These classes implement the different available functionalities and are classified into: 

* Core
* Input/Output
* or Components categories. 

Several applications [applications](applications) and projects are implemented in order to demonstrate the library usage. 

A more detailed description of the code listings can be found in the [library documentation](LICENSE.txt)  (generated by Doxygen)



## Software setup  

 Before using the library and start programming and interfacing hardware peripherals, some 
 software packages need to be installed in your system: 

* binutils: for getting tools like assembler, linker, ...
* gcc-avr : AVR GNU C cross-compiler
* avr-libc: AVR C library
* avrdude : driver program for downloading/uploading code and data from/to Atmel AVR Microcontrollers



### Linux

In Linux (Ubuntu in my case), the software packages can be installed as follows:

```
sudo apt-get update
sudo apt-get install gcc build-essential
sudo apt-get install gcc-avr binutils-avr avr-libc gdb-avr
sudo apt-get install avrdude
```

### Windows

In Windows, 



## Hardware setup  

* MCU chip either barebone or on a development board like an Arduino UNO
* A bunch of Leds, resistors, drivers, sensors and actuators
* A breadboard
* Jumper wires
* An AVR ISPProgrammer (optional)


## Applications

These applications demonstrate the usage of TahakomAVRLib in simple examples:

* [Blink a Led](applications/BlinkLed)


## Projects

These are relatively complex projects implemented using TahakomAVRLib


## Author

* Farid Oubbati
* Date: 12-May-2018
* Copyright (c) 2018

## License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for more details
