/*
 * 74hc4052.h
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
 * \file 74hc4052.h
 * 
 * \brief ATMega328 74HC4052 analog mux. library header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 06/06/2017
 * 
 * \defgroup mux_2_4x1 74HC4052
 * \ingroup drivers
 * \{ 
 */

#ifndef _74HC4052_H_
#define _74HC4052_H_

#include <stdint.h>

#include "74hc4051.h"
#include "gpio.h"

#undef _74HC4051_CH_A0
#undef _74HC4051_CH_A1
#undef _74HC4051_CH_A2
#undef _74HC4051_CH_A3
#undef _74HC4051_CH_A4
#undef _74HC4051_CH_A5
#undef _74HC4051_CH_A6
#undef _74HC4051_CH_A7

#define _74HC4052_CH_A0         0
#define _74HC4052_CH_A1         1
#define _74HC4052_CH_A2         2
#define _74HC4052_CH_A3         3

/**
 * \class 74HC4052
 * 
 * \brief A class to control the 74HC4052 analog multiplexer.
 */
class _74HC4052: public _74HC4051
{
    public:
        /**
         * \brief Class constructor.
         * 
         * \return None
         */
        _74HC4052();
        /**
         * \brief Class constructor.
         * 
         * In the constructor, the initialization of the enable and select pins are made.
         * 
         * \param s0_pin is the S0 pin on the Arduino Uno (see "utils/arduino_uno_pins.h").
         * \param s1_Pin is the S1 pin on the Arduino Uno (see "utils/arduino_uno_pins.h").
         * \param en_pin is the EN pin on the Arduino Uno (see "utils/arduino_uno_pins.h").
         * 
         * \return None
         */
        _74HC4052(uint8_t s0_pin, uint8_t s1_pin, uint8_t en_pin);
        /**
         * \brief Class destructor.
         * 
         * In the destructor, the input are disabled and the channel A0 is leaved selected.
         * 
         * \return None
         */
        ~_74HC4052();
        /**
         * \brief Selects a channel of the input.
         * 
         * \param channel is the input channel to be selected.
         * 
         * \return None
         */
        void SetChannel(uint8_t channel);
};

#endif // _74HC4052_H_
