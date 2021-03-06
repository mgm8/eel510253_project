/*
 * 74hc4051.cpp
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
 * \file 74hc4051.cpp
 * 
 * \brief ATMega328 74HC4051 analog mux. library implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \addtogroup mux_8x1 74HC4051
 * \{ 
 */

#include "74hc4051.h"

_74HC4051::_74HC4051()
{
    
}

_74HC4051::_74HC4051(uint8_t s0_pin, uint8_t s1_pin, uint8_t s2_pin, uint8_t en_pin)
{
    // Setting S0, S1, S2 and EN pins as output pins
    this->SetPins(s0_pin, s1_pin, s2_pin, en_pin);
    
    // Initializing with the input disabled
    this->Disable();
    
    // Initializing with channel A0 channel selected
    this->SetChannel(_74HC4051_CH_A0);
}

_74HC4051::~_74HC4051()
{
    // Disabling the input
    this->Disable();
    
    // Leaving with channel A0 selected
    this->SetChannel(_74HC4051_CH_A0);
}

void _74HC4051::SetPins(uint8_t s0_pin, uint8_t s1_pin, uint8_t s2_pin, uint8_t en_pin)
{
    s0.SetPin(s0_pin);
    s1.SetPin(s1_pin);
    s2.SetPin(s2_pin);
    en.SetPin(en_pin);
}

void _74HC4051::SetChannel(uint8_t channel)
{
    switch(channel)
    {
        case _74HC4051_CH_A0:   // Channel A0
            s0.Clear();
            s1.Clear();
            s2.Clear();
            break;
        case _74HC4051_CH_A1:   // Channel A1
            s0.Set();
            s1.Clear();
            s2.Clear();
            break;
        case _74HC4051_CH_A2:   // Channel A2
            s0.Clear();
            s1.Set();
            s2.Clear();
            break;
        case _74HC4051_CH_A3:   // Channel A3
            s0.Set();
            s1.Set();
            s2.Clear();
            break;
        case _74HC4051_CH_A4:   // Channel A4
            s0.Clear();
            s1.Clear();
            s2.Set();
            break;
        case _74HC4051_CH_A5:   // Channel A5
            s0.Set();
            s1.Clear();
            s2.Set();
            break;
        case _74HC4051_CH_A6:   // Channel A6
            s0.Clear();
            s1.Set();
            s2.Set();
            break;
        case _74HC4051_CH_A7:   // Channel A7
            s0.Set();
            s1.Set();
            s2.Set();
            break;
        default:                // Channel A0
            s0.Clear();
            s1.Clear();
            s2.Clear();
    }
}

void _74HC4051::Enable()
{
    en.Clear();
}

void _74HC4051::Disable()
{
    en.Set();
}

//! \} End of mux_8x1 implementation group
