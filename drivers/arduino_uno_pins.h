/*
 * arduino_uno_pins.h
 * 
 * Copyright 2017, Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * This file is part of EEL510253-Project.
 * 
 * EEL510253-Project is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * EEL510253-Project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *  
 * You should have received a copy of the GNU Lesser General Public
 * License along with EEL510253-Project; if not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \file arduino_uno_pins.h
 * 
 * \brief Arduino Uno pins map.
 * 
 * Address, port and pin of Arduino Uno on ATMega328p.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 06/06/2017
 * 
 * \defgroup uno_pins Arduino Uno Pins
 * \ingroup drivers
 * \{ 
 */

#ifndef ARDUINO_UNO_PINS_H_
#define ARDUINO_UNO_PINS_H_

#include <avr/io.h>

#define P0_DDR          DDRD
#define P0_PORT         PORTD
#define P0_PORT_PIN     PORTD0
#define P0_PIN          0x00

#define P1_DDR          DDRD
#define P1_PORT         PORTD
#define P1_PORT_PIN     PORTD1
#define P1_PIN          0x01

#define P2_DDR          DDRD
#define P2_PORT         PORTD
#define P2_PORT_PIN     PORTD2
#define P2_PIN          0x02

#define P3_DDR          DDRD
#define P3_PORT         PORTD
#define P3_PORT_PIN     PORTD3
#define P3_PIN          0x03

#define P4_DDR          DDRD
#define P4_PORT         PORTD
#define P4_PORT_PIN     PORTD4
#define P4_PIN          0x04

#define P5_DDR          DDRD
#define P5_PORT         PORTD
#define P5_PORT_PIN     PORTD5
#define P5_PIN          0x05

#define P6_DDR          DDRD
#define P6_PORT         PORTD
#define P6_PORT_PIN     PORTD6
#define P6_PIN          0x06

#define P7_DDR          DDRD
#define P7_PORT         PORTD
#define P7_PORT_PIN     PORTD7
#define P7_PIN          0x07

#define P8_DDR          DDRB
#define P8_PORT         PORTB
#define P8_PORT_PIN     PORTB0
#define P8_PIN          0x08

#define P9_DDR          DDRB
#define P9_PORT         PORTB
#define P9_PORT_PIN     PORTB1
#define P9_PIN          0x09

#define P10_DDR         DDRB
#define P10_PORT        PORTB
#define P10_PORT_PIN    PORTB2
#define P10_PIN         0x0A

#define P11_DDR         DDRB
#define P11_PORT        PORTB
#define P11_PORT_PIN    PORTB3
#define P11_PIN         0x0B

#define P12_DDR         DDRB
#define P12_PORT        PORTB
#define P12_PORT_PIN    PORTB4
#define P12_PIN         0x0C

#define P13_DDR         DDRB
#define P13_PORT        PORTB
#define P13_PORT_PIN    PORTB5
#define P13_PIN         0x0D

#define A0_DDR          DDRC
#define A0_PORT         PORTC
#define A0_PORT_PIN     PORTC0
#define A0_PIN          0x0E

#define A1_DDR          DDRC
#define A1_PORT         PORTC
#define A1_PORT_PIN     PORTC1
#define A1_PIN          0x0F

#define A2_DDR          DDRC
#define A2_PORT         PORTC
#define A2_PORT_PIN     PORTC2
#define A2_PIN          0x10

#define A3_DDR          DDRC
#define A3_PORT         PORTC
#define A3_PORT_PIN     PORTC3
#define A3_PIN          0x11

#define A4_DDR          DDRC
#define A4_PORT         PORTC
#define A4_PORT_PIN     PORTC4
#define A4_PIN          0x12

#define A5_DDR          DDRC
#define A5_PORT         PORTC
#define A5_PORT_PIN     PORTC5
#define A5_PIN          0x13

#endif // ARDUINO_UNO_PINS_H_

//! \} End of uno_pins group
