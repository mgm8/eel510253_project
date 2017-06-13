/*
 * packet.cpp
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
 * \file packet.cpp
 * 
 * \brief Packet class implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 11/06/2017
 * 
 * \addtogroup packet
 * \{ 
 */

#include "packet.h"

Packet::Packet()
{
    this->Clear();
}

Packet::Packet(uint8_t *p, uint8_t l)
{
    this->Clear();
    
    for(uint8_t i=0;i<l;i++)
    {
        payload[i] = p[i];
    }
    
    len = l;
}

Packet::~Packet()
{
    this->Clear();
}

void Packet::append(Packet p)
{
    for(uint8_t i=len; i<(len+p.len); i++)
    {
        payload[i] = p.payload[i-len];
    }
    len += p.len;
}

void Packet::append(uint8_t b)
{
    payload[len] = b;
    len++;
}

void Packet::append(double f)
{
    DoubleToPayload(f);
}

void Packet::operator = (Packet p)
{
    this->Clear();
    
    for(uint8_t i=0;i<p.len;i++)
    {
        payload[i] = p.payload[i];
    }
    
    len = p.len;
}

void Packet::operator = (uint8_t b)
{
    this->Clear();
    
    payload[0] = b;
    
    len = 0x01;
}

void Packet::operator = (double f)
{
    this->Clear();
    
    DoubleToPayload(f);
}

Packet Packet::operator + (Packet p)
{
    Packet pkt_buf;
    for(uint8_t i=0; i<len; i++)
    {
        pkt_buf.append(payload[i]);
    }
    
    for(uint8_t i=0; i<p.len; i++)
    {
        pkt_buf.append(p.payload[i]);
    }
    
    return pkt_buf;
}

Packet Packet::operator + (uint8_t b)
{
    Packet pkt_buf;
    
    pkt_buf = b;
    
    return *this + pkt_buf;
}

Packet Packet::operator + (double f)
{
    Packet pkt_buf;
    
    pkt_buf = f;
    
    return *this + pkt_buf;
}

void Packet::operator += (Packet p)
{
    *this = *this + p;
}

void Packet::operator += (uint8_t b)
{
    *this = *this + b;
}

void Packet::operator += (double f)
{
    *this = *this + f;
}

void Packet::Clear()
{
    for(uint8_t i=0;i<PACKET_MAX_SIZE;i++)
    {
        payload[i] = 0x00;
    }
    
    len = 0x00;
}

void Packet::DoubleToPayload(double f)
{
    if ((f >= 0) and (f < 100))
    {
        int8_t digit_3 = -1;
        while(f >= 0)
        {
            f -= 10.00;
            digit_3++;
        }
        f += 10.00;
        
        int8_t digit_2 = -1;
        while(f >= 0)
        {
            f -= 1.00;
            digit_2++;
        }
        f += 1.00;
        
        int8_t digit_1 = -1;
        while(f >= 0)
        {
            f -= 0.10;
            digit_1++;
        }
        f += 0.10;
        
        int8_t digit_0 = -1;
        while(f >= 0)
        {
            f -= 0.01;
            digit_0++;
        }
        
        this->append((uint8_t)digit_3);
        this->append((uint8_t)digit_2);
        this->append((uint8_t)'.');
        this->append((uint8_t)digit_1);
        this->append((uint8_t)digit_0);
    }
}

void Packet::get(uint8_t *pkt)
{
    pkt[0] = PACKET_SOD_BYTE;
    pkt[1] = len;
    for(uint8_t i=0; i<len; i++)
    {
        pkt[i+2] = payload[i];
    }
}

uint8_t Packet::size()
{
    return len + 2;
}

//! \} End of packet group
