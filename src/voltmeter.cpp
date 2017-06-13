/*
 * voltmeter.cpp
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
 * \file voltmeter.cpp
 * 
 * \brief Voltmeter implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \addtogroup voltmeter
 * \{ 
 */

#include <drivers/arduino_uno_pins.h>

#include "voltmeter.h"

Voltmeter::Voltmeter()
{
    
}

Voltmeter::Voltmeter(uint8_t s0, uint8_t s1, uint8_t en)
{
    this->SetPins(s0, s1, en);
}

Voltmeter::~Voltmeter()
{
    
}

void Voltmeter::SetPins(uint8_t s0, uint8_t s1, uint8_t en)
{
    mux.SetPins(s0, s1, en);
}

Reading Voltmeter::Read(uint8_t channel)
{
    // Selecting the given channel of the mux.
    mux.SetChannel(channel);
    
    // Enabling the input of the mux.
    mux.Enable();
    
    // Reading the voltages from the given channel
    Reading reading;
    reading.r0 = adc_0.ReadVoltage(VOLTMETER_ADC_PORT_0);
    reading.r1 = adc_1.ReadVoltage(VOLTMETER_ADC_PORT_1);
    
    // Disabling the input of the mux.
    mux.Disable();
    
    return reading;
}



//! \} End of voltmeter implementation group
