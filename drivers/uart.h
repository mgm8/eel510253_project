/*
 * uart.h
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
 * \file uart.h
 * 
 * \brief UART class header for ATMega328P.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 14/11/2016
 * 
 * \defgroup uart UART
 * \ingroup drivers
 * \{ 
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#ifndef F_OSC
    #define F_OSC 16000000UL
#endif // F_OSC

/**
 * \class UART
 * 
 * \brief This clas implements the UART comunication in the ATMega328P.
 */
class UART
{
    public:
        /**
         * \brief Constructor of the UART.
         * 
         * This constructor only initializes the object.
         */
        UART();
        /**
         * \brief Constructor of the UART.
         * 
         * This constructor initializes the object, and call the Init method (That initializes the UART communication).
         * 
         * \param baudrate is the baudrate of the UART connection.
         */
        UART(uint16_t baudrate);
        /**
         * \brief Destructor of the UART.
         * 
         * The destructor does nothing.
         */
        ~UART();
        /**
         * \brief Initializes the UART comunication.
         * 
         * \param baudrate is the desired baudrate.
         * 
         * \return none
         */
        void Init(uint16_t baudrate);
        /**
         * \brief Checks if something was received.
         * 
         * \return It returns:
         *          -\b TRUE if there is a byte in the RX buffer (Something was received).
         *          -\b FALSE if there is nothing in the RX buffer.
         */
        bool Available();
        /**
         * \brief Flushes the received data in the RX buffer.
         * 
         * \return none
         */
        void Flush();
        /**
         * \brief Reads a byte from the RX buffer.
         * 
         * \return A byte from the RX buffer.
         */
        uint8_t ReadByte();
        /**
         * \brief Writes a byte in the TX buffer.
         * 
         * \param byte is the byte to be written.
         * 
         * \return none
         */
        void WriteByte(uint8_t byte);
        /**
         * \brief Writes a message in the TX buffer.
         *  
         * \param msg is a pointer to an array containing the message.
         * 
         * \return none
         */
        void Write(uint8_t* msg);
};

#endif // UART_H_

//! \} End of uart group
