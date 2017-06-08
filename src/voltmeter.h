/*
 * voltmeter.h
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
 * \file voltmeter.h
 * 
 * \brief Voltmeter header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \defgroup voltmeter Voltmeter
 * \ingroup src
 * \{ 
 */

#ifndef VOLTMETER_H_
#define VOLTMETER_H_

#include <drivers/74hc4052.h>
#include <drivers/adc.h>

#define VOLTMETER_ADC_PORT_0   ADC_PORT_0
#define VOLTMETER_ADC_PORT_1   ADC_PORT_1

#define VOLTMETER_CH_0         _74HC4052_CH_A0
#define VOLTMETER_CH_1         _74HC4052_CH_A1
#define VOLTMETER_CH_2         _74HC4052_CH_A2
#define VOLTMETER_CH_3         _74HC4052_CH_A3

/**
 * \struct Reading
 * 
 * \brief A struct to store the readings from a given channel.
 */
struct Reading
{
    double r0;      /**< . */
    double r1;      /**< . */
    /**
     * \brief Struct constructor.
     * 
     * \param a is the value of the first reading.
     * \param b is the value of the seconds reading.
     * 
     * \return None
     */
    Reading(double a, double b)
    {
        r0 = a;
        r1 = b;
    }
    /**
     * \brief Struct constructor.
     * 
     * \param R
     * 
     * \return None
     */
/*    Reading(Reading &R)
    {
        r0 = R.r0;
        r1 = R.r1;
    }*/
    /**
     * \brief Struct operator =
     * 
     * \param R is another Reading object.
     * 
     * \return A pointer to this struct.
     */
    void operator = (Reading R)
    {
        r0 = R.r0;
        r1 = R.r1;
    }
};

/**
 * \class Voltmeter
 * 
 * \brief A class to describe a multichannel voltmeter.
 */
class Voltmeter
{
    protected:
        ADConverter *adc_0;         /**< . */
        ADConverter *adc_1;         /**< . */
        _74HC4052 *mux;             /**< . */
    public:
        /**
         * \brief 
         * 
         * \return None
         */
        Voltmeter();
        /**
         * \brief Class constructor.
         * 
         * \param s0
         * \param s1
         * \param en
         * 
         * \return None
         */
        Voltmeter(uint8_t s0, uint8_t s1, uint8_t en);
        /**
         * \brief Class destructor.
         * 
         * \return None
         */
        ~Voltmeter();
        /**
         * \brief Reads the voltage from the voltmeter (in V).
         * 
         * \param channel is the channel to read the voltage.
         * 
         * \return The voltage value of the given channel.
         */
        Reading Read(uint8_t channel);
};

#endif // VOLTMETER_H_

//! \} End of voltmeter group
