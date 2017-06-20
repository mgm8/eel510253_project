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

#include <drivers/adc.h>

#define AMMETER_ADC_PORT_0      ADC_PORT_2
#define AMMETER_ADC_PORT_1      ADC_PORT_3

#define AMMETER_CHANNEL_0       0x00
#define AMMETER_CHANNEL_1       0x01

/**
 * \class Ammeter
 * 
 * \brief Ammeter class.
 */
class Ammeter
{
    protected:
        ADConverter adc_0;      /**< . */
        ADConverter adc_1;      /**< . */
    public:
        /**
         * \brief Object constructor.
         * 
         * \return None
         */
        Ammeter();
        /**
         * \brief Object destructor.
         * 
         * \return None
         */
        ~Ammeter();
        /**
         * \brief Reads the current from the ammeter (in mA).
         * 
         * \return The current of the given channel.
         */
        double Read(uint8_t channel);
};

#endif // AMMETER_H_

//! \} End of ammeter group
