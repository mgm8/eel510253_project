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
 * \brief ATMega328 74HC4052 analog mux. library implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 06/06/2017
 * 
 * \addtogroup mux_2_4x1
 * \{ 
 */

#include "74hc4052.h"

_74HC4052::_74HC4052()
{
    
}

_74HC4052::_74HC4052(uint8_t s0_pin, uint8_t s1_pin, uint8_t en_pin)
{
    // Setting S0, S1, S2 and EN pins as output pins
    s0 = new GPIOAsOutput(s0_pin);
    s1 = new GPIOAsOutput(s1_pin);
    //s2 = NULL;
    en = new GPIOAsOutput(en_pin);
    
    // Initializing with the input disabled
    this->Disable();
    
    // Initializing with channel A0 channel selected
    this->SetChannel(_74HC4052_CH_A0);
}

_74HC4052::~_74HC4052()
{
    // Disabling the input
    this->Disable();
    
    // Leaving with channel A0 selected
    this->SetChannel(_74HC4052_CH_A0);
    
    delete s0;
    delete s1;
    delete en;
}

void _74HC4052::SetChannel(uint8_t channel)
{
    switch(channel)
    {
        case _74HC4052_CH_A0:   // Channel A0
            s0->Clear();
            s1->Clear();
            break;
        case _74HC4052_CH_A1:   // Channel A1
            s0->Set();
            s1->Clear();
            break;
        case _74HC4052_CH_A2:   // Channel A2
            s0->Clear();
            s1->Set();
            break;
        case _74HC4052_CH_A3:   // Channel A3
            s0->Set();
            s1->Set();
            break;
        default:                // Channel A0
            s0->Clear();
            s1->Clear();
    }
}

//! \} End of mux_2_4x1 implementation group
