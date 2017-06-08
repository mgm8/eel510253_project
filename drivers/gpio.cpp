/*
 * gpio.cpp
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
 * \file gpio.cpp
 * 
 * \brief Arduino Uno GPIO control implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 06/06/2017
 * 
 * \addtogroup gpio
 * \{ 
 */

#include "gpio.h"
#include "arduino_uno_pins.h"

//##########################################################
//-- GPIO --------------------------------------------------
//##########################################################

GPIO::GPIO()
{
    
}

GPIO::GPIO(uint8_t p)
{
    this->SetPin(p);
    direction = GPIO_DIR_UNDEF;
}

GPIO::GPIO(uint8_t p, uint8_t dir)
{
    this->SetPin(p);
    this->SetDirection(dir);
}

GPIO::~GPIO()
{
    
}

void GPIO::SetPin(uint8_t p)
{    
    pin = p;
}

uint8_t GPIO::GetPin()
{
    return pin;
}

void GPIO::SetDirection(uint8_t dir)
{            
    switch(dir)
    {
        case GPIO_AS_OUTPUT:
            switch(pin)
            {
                case P0_PIN:
                    P0_DDR |= 1 << P0_PORT_PIN;
                    break;
                case P1_PIN:
                    P1_DDR |= 1 << P1_PORT_PIN;
                    break;
                case P2_PIN:
                    P2_DDR |= 1 << P2_PORT_PIN;
                    break;
                case P3_PIN:
                    P3_DDR |= 1 << P3_PORT_PIN;
                    break;
                case P4_PIN:
                    P4_DDR |= 1 << P4_PORT_PIN;
                    break;
                case P5_PIN:
                    P5_DDR |= 1 << P5_PORT_PIN;
                    break;
                case P6_PIN:
                    P6_DDR |= 1 << P6_PORT_PIN;
                    break;
                case P7_PIN:
                    P7_DDR |= 1 << P7_PORT_PIN;
                    break;
                case P8_PIN:
                    P8_DDR |= 1 << P8_PORT_PIN;
                    break;
                case P9_PIN:
                    P9_DDR |= 1 << P9_PORT_PIN;
                    break;
                case P10_PIN:
                    P10_DDR |= 1 << P10_PORT_PIN;
                    break;
                case P11_PIN:
                    P11_DDR |= 1 << P11_PORT_PIN;
                    break;
                case P12_PIN:
                    P12_DDR |= 1 << P12_PORT_PIN;
                    break;
                case P13_PIN:
                    P13_DDR |= 1 << P13_PORT_PIN;
                    break;
                default:
                    break;
            }
            direction = GPIO_AS_OUTPUT;
            break;
        case GPIO_AS_INPUT:
            switch(pin)
            {
                case P0_PIN:
                    P0_DDR &= ~(1 << P0_PORT_PIN);
                    break;
                case P1_PIN:
                    P1_DDR &= ~(1 << P1_PORT_PIN);
                    break;
                case P2_PIN:
                    P2_DDR &= ~(1 << P2_PORT_PIN);
                    break;
                case P3_PIN:
                    P3_DDR &= ~(1 << P3_PORT_PIN);
                    break;
                case P4_PIN:
                    P4_DDR &= ~(1 << P4_PORT_PIN);
                    break;
                case P5_PIN:
                    P5_DDR &= ~(1 << P5_PORT_PIN);
                    break;
                case P6_PIN:
                    P6_DDR &= ~(1 << P6_PORT_PIN);
                    break;
                case P7_PIN:
                    P7_DDR &= ~(1 << P7_PORT_PIN);
                    break;
                case P8_PIN:
                    P8_DDR &= ~(1 << P8_PORT_PIN);
                    break;
                case P9_PIN:
                    P9_DDR &= ~(1 << P9_PORT_PIN);
                    break;
                case P10_PIN:
                    P10_DDR &= ~(1 << P10_PORT_PIN);
                    break;
                case P11_PIN:
                    P11_DDR &= ~(1 << P11_PORT_PIN);
                    break;
                case P12_PIN:
                    P12_DDR &= ~(1 << P12_PORT_PIN);
                    break;
                case P13_PIN:
                    P13_DDR &= ~(1 << P13_PORT_PIN);
                    break;
                default:
                    break;
            }
            direction = GPIO_AS_INPUT;
            break;
        default:
            // throw something
            break;
    }
}

uint8_t GPIO::GetDirection()
{
    return direction;
}

void GPIO::Set()
{
    if (direction == GPIO_AS_OUTPUT)
    {
        switch(pin)
        {
            case P0_PIN:
                P0_PORT |= 1 << P0_PORT_PIN;
                break;
            case P1_PIN:
                P1_PORT |= 1 << P1_PORT_PIN;
                break;
            case P2_PIN:
                P2_PORT |= 1 << P2_PORT_PIN;
                break;
            case P3_PIN:
                P3_PORT |= 1 << P3_PORT_PIN;
                break;
            case P4_PIN:
                P4_PORT |= 1 << P4_PORT_PIN;
                break;
            case P5_PIN:
                P5_PORT |= 1 << P5_PORT_PIN;
                break;
            case P6_PIN:
                P6_PORT |= 1 << P6_PORT_PIN;
                break;
            case P7_PIN:
                P7_PORT |= 1 << P7_PORT_PIN;
                break;
            case P8_PIN:
                P8_PORT |= 1 << P8_PORT_PIN;
                break;
            case P9_PIN:
                P9_PORT |= 1 << P9_PORT_PIN;
                break;
            case P10_PIN:
                P10_PORT |= 1 << P10_PORT_PIN;
                break;
            case P11_PIN:
                P11_PORT |= 1 << P11_PORT_PIN;
                break;
            case P12_PIN:
                P12_PORT |= 1 << P12_PORT_PIN;
                break;
            case P13_PIN:
                P13_PORT |= 1 << P13_PORT_PIN;
                break;
            default:
                break;
        }
    }
}

void GPIO::Clear()
{
    if (direction == GPIO_AS_OUTPUT)
    {
        switch(pin)
        {
            case P0_PIN:
                P0_PORT &= ~(1 << P0_PORT_PIN);
                break;
            case P1_PIN:
                P1_PORT &= ~(1 << P1_PORT_PIN);
                break;
            case P2_PIN:
                P2_PORT &= ~(1 << P2_PORT_PIN);
                break;
            case P3_PIN:
                P3_PORT &= ~(1 << P3_PORT_PIN);
                break;
            case P4_PIN:
                P4_PORT &= ~(1 << P4_PORT_PIN);
                break;
            case P5_PIN:
                P5_PORT &= ~(1 << P5_PORT_PIN);
                break;
            case P6_PIN:
                P6_PORT &= ~(1 << P6_PORT_PIN);
                break;
            case P7_PIN:
                P7_PORT &= ~(1 << P7_PORT_PIN);
                break;
            case P8_PIN:
                P8_PORT &= ~(1 << P8_PORT_PIN);
                break;
            case P9_PIN:
                P9_PORT &= ~(1 << P9_PORT_PIN);
                break;
            case P10_PIN:
                P10_PORT &= ~(1 << P10_PORT_PIN);
                break;
            case P11_PIN:
                P11_PORT &= ~(1 << P11_PORT_PIN);
                break;
            case P12_PIN:
                P12_PORT &= ~(1 << P12_PORT_PIN);
                break;
            case P13_PIN:
                P13_PORT &= ~(1 << P13_PORT_PIN);
                break;
            default:
                break;
        }
    }
}

void GPIO::Toggle()
{
    if (direction == GPIO_AS_OUTPUT)
    {
        switch(pin)
        {
            case P0_PIN:
                P0_PORT ^= 1 << P0_PORT_PIN;
                break;
            case P1_PIN:
                P1_PORT ^= 1 << P1_PORT_PIN;
                break;
            case P2_PIN:
                P2_PORT ^= 1 << P2_PORT_PIN;
                break;
            case P3_PIN:
                P3_PORT ^= 1 << P3_PORT_PIN;
                break;
            case P4_PIN:
                P4_PORT ^= 1 << P4_PORT_PIN;
                break;
            case P5_PIN:
                P5_PORT ^= 1 << P5_PORT_PIN;
                break;
            case P6_PIN:
                P6_PORT ^= 1 << P6_PORT_PIN;
                break;
            case P7_PIN:
                P7_PORT ^= 1 << P7_PORT_PIN;
                break;
            case P8_PIN:
                P8_PORT ^= 1 << P8_PORT_PIN;
                break;
            case P9_PIN:
                P9_PORT ^= 1 << P9_PORT_PIN;
                break;
            case P10_PIN:
                P10_PORT ^= 1 << P10_PORT_PIN;
                break;
            case P11_PIN:
                P11_PORT ^= 1 << P11_PORT_PIN;
                break;
            case P12_PIN:
                P12_PORT ^= 1 << P12_PORT_PIN;
                break;
            case P13_PIN:
                P13_PORT ^= 1 << P13_PORT_PIN;
                break;
            default:
                break;
        }
    }
}

bool GPIO::Read()
{
    switch(pin)
    {
        case P0_PIN:
            return ((P0_PORT >> P0_PORT_PIN) & 0x01)? true: false;
            break;
        case P1_PIN:
            return ((P1_PORT >> P1_PORT_PIN) & 0x01)? true: false;
            break;
        case P2_PIN:
            return ((P2_PORT >> P2_PORT_PIN) & 0x01)? true: false;
            break;
        case P3_PIN:
            return ((P3_PORT >> P3_PORT_PIN) & 0x01)? true: false;
            break;
        case P4_PIN:
            return ((P4_PORT >> P4_PORT_PIN) & 0x01)? true: false;
            break;
        case P5_PIN:
            return ((P5_PORT >> P5_PORT_PIN) & 0x01)? true: false;
            break;
        case P6_PIN:
            return ((P6_PORT >> P6_PORT_PIN) & 0x01)? true: false;
            break;
        case P7_PIN:
            return ((P7_PORT >> P7_PORT_PIN) & 0x01)? true: false;
            break;
        case P8_PIN:
            return ((P8_PORT >> P8_PORT_PIN) & 0x01)? true: false;
            break;
        case P9_PIN:
            return ((P9_PORT >> P9_PORT_PIN) & 0x01)? true: false;
            break;
        case P10_PIN:
            return ((P10_PORT >> P10_PORT_PIN) & 0x01)? true: false;
            break;
        case P11_PIN:
            return ((P11_PORT >> P11_PORT_PIN) & 0x01)? true: false;
            break;
        case P12_PIN:
            return ((P12_PORT >> P12_PORT_PIN) & 0x01)? true: false;
            break;
        case P13_PIN:
            return ((P13_PORT >> P13_PORT_PIN) & 0x01)? true: false;
            break;
        default:
            return false;
            break;
    }
}

//##########################################################
//-- GPIOAsOutput ------------------------------------------
//##########################################################

GPIOAsOutput::GPIOAsOutput(uint8_t p)
{
    this->SetPin(p);
    this->SetDirection(GPIO_AS_OUTPUT);
    this->Clear();
}

GPIOAsOutput::GPIOAsOutput(uint8_t p, uint8_t dir)
{
    this->SetPin(p);
    this->SetDirection(GPIO_AS_OUTPUT);
    this->Clear();
}

//##########################################################
//-- GPIOAsInput -------------------------------------------
//##########################################################

GPIOAsInput::GPIOAsInput(uint8_t p)
{
    this->SetPin(p);
    this->SetDirection(GPIO_AS_INPUT);
}

GPIOAsInput::GPIOAsInput(uint8_t p, uint8_t dir)
{
    this->SetPin(p);
    this->SetDirection(GPIO_AS_INPUT);
}

//! \} End of gpio group
