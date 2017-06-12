/*
 * smart_cell.cpp
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
 * \file smart_cell.cpp
 * 
 * \brief Implementation of the main class of the program.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \addtogroup smart_cell
 * \{ 
 */

#include <util/delay.h>
#include <drivers/arduino_uno_pins.h>
#include <drivers/gpio.h>

#include "smart_cell.h"
#include "packet.h"

SmartCell::SmartCell()
{
    volt = new Voltmeter(P1_PIN, P2_PIN, P3_PIN);
    amp = new Ammeter(P4_PIN, P5_PIN, P6_PIN);
    uart = new UART(9600);
}

SmartCell::~SmartCell()
{
    delete volt;
    delete amp;
    delete uart;
}

void SmartCell::Run()
{
    GPIOAsOutput led(P13_PIN);
    
    while(1)
    {
        Packet pkt;
        
        Reading v = volt->Read(VOLTMETER_CH_0);
        //Reading i = amp->Read(AMMETER_CH_0);
        pkt += v.r0;
        pkt += v.r1;
        _delay_ms(50);
        
        v = volt->Read(VOLTMETER_CH_1);
        pkt += v.r0;
        pkt += v.r1;
        _delay_ms(50);

        v = volt->Read(VOLTMETER_CH_2);
        pkt += v.r0;
        pkt += v.r1;
        _delay_ms(50);
        
        v = volt->Read(VOLTMETER_CH_3);
        pkt += v.r0;
        pkt += v.r1;
        _delay_ms(50);
        
        uint8_t pkt_buf[PACKET_MAX_SIZE];
        pkt.get(pkt_buf);
        
        for(uint8_t i=0; i<pkt.size();i++)
        {
            uart->WriteByte(pkt_buf[i]);
        }
        
        _delay_ms(800);
        
        led.Toggle();
    }
}

//! \} End of smart_cell implementation group
