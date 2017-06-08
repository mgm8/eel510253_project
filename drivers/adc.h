/*
 * adc.h
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
 * \file adc.h
 * 
 * \brief ATMega328 ADC library header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 28/05/2017
 * 
 * \defgroup adc ADC
 * \ingroup drivers
 * \{ 
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define ADC_VREF        5       // Reference voltage.
#define ADC_MAX_VALUE   1024    // 10 bit ADC max. value

#define ADC_PORT_0      0
#define ADC_PORT_1      1
#define ADC_PORT_2      2
#define ADC_PORT_3      3
#define ADC_PORT_4      4
#define ADC_PORT_5      5

/**
 * \class ADC
 * 
 * \brief ATMega328 analog to digital converter class.
 */
class ADConverter
{
    public:
        /**
         * \brief ADC constructor.
         * 
         * \return None
         */
        ADConverter();
        /**
         * \brief ADC destructor.
         * 
         * \return None
         */
        ~ADConverter();
        /**
         * \brief Reads the ADC value of a given channel.
         * 
         * \param pin is the ADC pin.
         * 
         * \return The 10 bit value of the reading.
         */
        uint16_t Read(uint8_t pin);
        /**
         * \brief Reads the ADC value and converts it to a voltage value.
         * 
         * \param pin is the ADC pin.
         * 
         * \return The voltage value of the ADC reading
         */
        double ReadVoltage(uint8_t pin);
        /**
         * \brief Converts a raw reading to a real voltage value.
         * 
         * \param reading is the raw 10 bit value of an ADC reading.
         * 
         * \return The equivalent voltage of the input reading.
         */
        double ReadingToVoltage(uint16_t reading);
};

#endif // ADC_H_

//! \} End of adc group
