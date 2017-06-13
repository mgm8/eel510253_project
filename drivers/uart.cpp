/*
 * uart.cpp
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
 * \file uart.cpp
 * 
 * \brief UART implementation for ATMega328P.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 14/11/2016
 * 
 * \addtogroup uart
 * \{ 
 */

#include <avr/io.h>

#include "uart.h"

UART::UART()
{
    
}

UART::UART(uint16_t baudrate)
{
    this->Init(baudrate);
}

UART::~UART()
{
    
}

void UART::Init(uint16_t baudrate)
{
    uint16_t ubrr = (uint16_t)(2*F_OSC/16/baudrate-1);
    
    // Set baud rate
    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)(ubrr);
    
    // Enable receiver, trasmitter and receiver interrupt
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    
    // Set frame format: 8 data bits, 1 stop bit
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
}

bool UART::Available()
{
    return (1 << RXC0);
}

void UART::Flush()
{
    uint8_t dummy;
    while(UCSR0A & (1 << RXC0))
    {
        dummy = UDR0;
    }
}

uint8_t UART::ReadByte()
{
    // Wait for data to be received
    while(!(UCSR0A & (1 << RXC0)))
    {
        
    }

    // Get and return received data from buffer
    return UDR0;
}

void UART::WriteByte(uint8_t byte)
{
    // Wait for empty transmit buffer
    while(!(UCSR0A & (1 << UDRE0)))
    {
        
    }
    
    // Put data into buffer, sends the data
    UDR0 = byte;
}

void UART::Write(uint8_t* s)
{
    while(*s)
    {
        this->WriteByte(*s);
        s++;
    }
}

//! \} End of uart group
