/*
 * packet.h
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
 * \file packet.h
 * 
 * \brief Packet class header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 11/06/2017
 * 
 * \defgroup packet Packet
 * \ingroup src
 * \{ 
 */

#ifndef PACKET_H_
#define PACKET_H_

#include <stdint.h>

#define PACKET_MAX_SIZE     64

#define PACKET_SOD_BYTE     0x7E

class Packet;

/**
 * \class Packet
 * 
 * \brief 
 */
class Packet
{
        uint8_t payload[PACKET_MAX_SIZE];   /**< . */
        uint8_t len;                        /**< . */
        /**
         * \brief Concatenates double into the packet payload.
         * 
         * \return None
         */
        void DoubleToPayload(double f);
    public:
        /**
         * \brief Constructor with a empty packet.
         * 
         * \return None
         */
        Packet();
        /**
         * \brief Construtor with a initial packet.
         * 
         * \param p is a pointer to an array of bytes.
         * \param l is the lenght if the payload.
         * 
         * \return None
         */
        Packet(uint8_t *p, uint8_t l);
        /**
         * \brief Destructor
         * 
         * \return None
         */
        ~Packet();        
        /**
         * \brief Appends another packet to this packet.
         * 
         * \param p is another packet object.
         * 
         * \return None
         */
        void append(Packet p);
        /**
         * \brief Appends a uint8_t to the payload.
         * 
         * \param b is a byte to append.
         * 
         * \return None
         */
        void append(uint8_t b);
        /**
         * \brief Appends a double to the payload.
         * 
         * \param f is a double to append.
         * 
         * \return None
         */
        void append(double f);
        /**
         * \brief = operator overload (For another Packer object).
         * 
         * \param p is another Packet.
         * 
         * \return None
         */
        void operator = (Packet p);
        /**
         * \brief = operator overload (For a uint8_t variable).
         * 
         * \param b is a byte.
         * 
         * \return None
         */
        void operator = (uint8_t b);
        /**
         * \brief = operator overload (For a double variable).
         * 
         * \param f is a double to be converted to a sequence of uint8_t.
         * 
         * \return None
         */
        void operator = (double f);
        /**
         * \brief 
         * 
         * \param 
         * 
         * \return 
         */
        Packet operator + (Packet p);
        /**
         * \brief 
         * 
         * \param 
         * 
         * \return 
         */
        Packet operator + (uint8_t b);
        /**
         * \brief 
         * 
         * \param 
         * 
         * \return 
         */
        Packet operator + (double f);
        /**
         * \brief 
         * 
         * \param 
         * 
         * \return None
         */
        void operator += (Packet p);
        /**
         * \brief 
         * 
         * \param 
         * 
         * \return None
         */
        void operator += (uint8_t b);
        /**
         * \brief 
         * 
         * \param 
         * 
         * \return None
         */
        void operator += (double f);
        /**
         * \brief 
         * 
         * \return None
         */
        void Clear();
        /**
         * \brief 
         * 
         * \param pkt is a pointer to an array to return the packet (With SOD, size and payload).
         * 
         * \return None
         */
        void get(uint8_t *pkt);
        /**
         * \brief Gets the size of the packet (With SOD, size and payload).
         * 
         * \return The size of the packet.
         */
        uint8_t size();
};

#endif // PACKET_H_

//! \} End of packet group
