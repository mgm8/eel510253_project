/*
 * ammeter.h
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
 * \file ammeter.h
 * 
 * \brief Ammeter header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \defgroup ammeter Ammeter
 * \ingroup src
 * \{ 
 */

#ifndef AMMETER_H_
#define AMMETER_H_

#include <drivers/74hc4052.h>
#include <drivers/adc.h>

#include "voltmeter.h"

#define AMMETER_CH_0        _74HC4052_CH_A0
#define AMMETER_CH_1        _74HC4052_CH_A1
#define AMMETER_CH_2        _74HC4052_CH_A2
#define AMMETER_CH_3        _74HC4052_CH_A3

/**
 * \class Ammeter
 * 
 * \brief 
 */
class Ammeter: public Voltmeter
{
    public:
        /**
         * \brief 
         * 
         * \return None
         */
        Ammeter();
        /**
         * \brief 
         * 
         * \return None
         */
        Ammeter(uint8_t s0, uint8_t s1, uint8_t en);
        /**
         * \brief Reads the current from the ammeter (in mA).
         * 
         * \return The current of the given channel.
         */
        double Read(uint8_t channel);
};

#endif // AMMETER_H_

//! \} End of ammeter group
