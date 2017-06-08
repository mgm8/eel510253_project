/*
 * adc.cpp
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
 * \file adc.cpp
 * 
 * \brief ATMega328 ADC library implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 28/05/2017
 * 
 * \addtogroup adc
 * \{ 
 */

#include <avr/io.h>

#include "adc.h"

ADConverter::ADConverter()
{
    // Select Vref=AVcc
    ADMUX |= (1 << REFS0);
    
    // Set prescaller to 128 and enable ADC 
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}

ADConverter::~ADConverter()
{
    
}

uint16_t ADConverter::Read(uint8_t pin)
{
    // Select ADC channel with safety mask
    ADMUX &= 0xF0;
    ADMUX |= pin;
    
    // Single conversion mode
    ADCSRA |= 1 << ADSC;
    
    // Wait until ADC conversion is complete
    while(ADCSRA & (1 << ADSC))
    {
        
    }
    
    return ADC;
}

double ADConverter::ReadVoltage(uint8_t pin)
{
    return (double)ADC_VREF/ADC_MAX_VALUE*Read(pin);
}

double ADConverter::ReadingToVoltage(uint16_t reading)
{
    return (double)ADC_VREF/ADC_MAX_VALUE*reading;
}

//! \} End of adc implementation group
