# EEL510253 Final Project - A smart control to a solar panel

## Hardware Dependencies

* ATMega328P (or Arduino Uno)
* 74HC4051 or 74HC4052 analog multiplexer

## Software Dependencies

* avr-gcc
* avr-dude

If you have the Arduino IDE installed, you already have these libraries in your system.

## Compiling and Building

You can compile and build the source code with the following commands:

```sh
$ make
$ make hex
```

## Uploading to ATMega328P

You can upload the program to the ATMega328P with following command:

```sh
$ make flash
```

All the configuration, like device address, baud rate, etc, can be modified in the main Makefile.

