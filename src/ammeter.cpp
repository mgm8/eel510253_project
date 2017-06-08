/*
 * ammeter.cpp
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
 * \file ammeter.cpp
 * 
 * \brief Ammeter implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \addtogroup ammeter
 * \{ 
 */

#include "ammeter.h"

Ammeter::Ammeter()
{
    
}

Ammeter::Ammeter(uint8_t s0, uint8_t s1, uint8_t en)
{
    adc_0 = new ADConverter;
    adc_1 = new ADConverter;
    mux = new _74HC4052(s0, s1, en);
}

double Ammeter::Read(uint8_t channel)
{
    return 0;
}

//! \} End of ammeter implementation group
