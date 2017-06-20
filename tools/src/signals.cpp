/*
 * signals.cpp
 * 
 * Copyright 2017, Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * This file is part of Smart-Panel-Control.
 * 
 * Smart-Panel-Control is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * Smart-Panel-Control is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Smart-Panel-Control. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \file signals.cpp
 * 
 * \brief Signals handlers implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 07/05/2017
 * 
 * \addtogroup signals
 * \{
 */

#include <gtkmm.h>
#include <stdint.h>
#include <vector>
#include <string>

#include "signals.h"
#include "global_var.h"
#include "error.h"

void on_togglebutton1_toggled()
{
    if (widgets.togglebutton_open_close_port->get_active())
    {
        int baudrate;
        
        auto br = widgets.entry_baudrate->get_text();
        
        if (br == "50")             baudrate = 50;
        else if (br == "75")        baudrate = 75;
        else if (br == "110")       baudrate = 110;
        else if (br == "134")       baudrate = 134;
        else if (br == "150")       baudrate = 150;
        else if (br == "200")       baudrate = 200;
        else if (br == "300")       baudrate = 300;
        else if (br == "600")       baudrate = 600;
        else if (br == "1200")      baudrate = 1200;
        else if (br == "1800")      baudrate = 1800;
        else if (br == "2400")      baudrate = 2400;
        else if (br == "4800")      baudrate = 4800;
        else if (br == "9600")      baudrate = 9600;
        else if (br == "19200")     baudrate = 19200;
        else if (br == "38400")     baudrate = 38400;
        else if (br == "57600")     baudrate = 57600;
        else if (br == "115200")    baudrate = 115200;
        else if (br == "230400")    baudrate = 230400;
        else                        baudrate = 9600;
        
        if (uart.Open(widgets.entry_serial_port->get_text().c_str(), baudrate))
        {
            widgets.entry_serial_port->set_sensitive(false);
            widgets.entry_baudrate->set_sensitive(false);
            
            widgets.switch_cell0->set_sensitive(false);
            widgets.switch_cell1->set_sensitive(false);
            widgets.switch_cell2->set_sensitive(false);
            widgets.switch_cell3->set_sensitive(false);
            widgets.switch_cell4->set_sensitive(false);
            widgets.switch_cell5->set_sensitive(false);
            widgets.switch_cell6->set_sensitive(false);
            widgets.switch_cell7->set_sensitive(false);
        }
        else
        {
            Error("Error opening the serial port!", "Verify if the device is connected or the address is correct!");
            
            widgets.togglebutton_open_close_port->set_active(false);
        }
    }
    else
    {
        uart.Close();
        
        widgets.entry_serial_port->set_sensitive(true);
        widgets.entry_baudrate->set_sensitive(true);
        
        widgets.switch_cell0->set_sensitive(true);
        widgets.switch_cell1->set_sensitive(true);
        widgets.switch_cell2->set_sensitive(true);
        widgets.switch_cell3->set_sensitive(true);
        widgets.switch_cell4->set_sensitive(true);
        widgets.switch_cell5->set_sensitive(true);
        widgets.switch_cell6->set_sensitive(true);
        widgets.switch_cell7->set_sensitive(true);
        
        widgets.label_voltage_cell0->set_text("0 V");
        widgets.label_voltage_cell1->set_text("0 V");
        widgets.label_voltage_cell2->set_text("0 V");
        widgets.label_voltage_cell3->set_text("0 V");
        widgets.label_voltage_cell4->set_text("0 V");
        widgets.label_voltage_cell5->set_text("0 V");
        widgets.label_voltage_cell6->set_text("0 V");
        widgets.label_voltage_cell7->set_text("0 V");
        
        widgets.label_current_group0->set_text("0 mA");
        widgets.label_current_group1->set_text("0 mA");
    }
}

bool timer_handler()
{    
    if (uart.isOpened())
    {
        unsigned int bytes_buf = uart.DataAvailable();
        if (bytes_buf >= 62)
        {
            std::vector<uint8_t> pkt;
            
            while(bytes_buf--)
            {
                pkt.push_back(uart.GetByte());
            }
            
            uart.Flush();
            
            if ((pkt[0] == 0x7E) and (pkt[1] == 0x3C))
            {
                if (pkt[2] == 0x00)
                {
                    widgets.switch_cell0->set_active(false);
                }
                else
                {
                    widgets.switch_cell0->set_active(true);
                }
                
                widgets.label_voltage_cell0->set_text(receive_voltage(pkt, 3, 7));
                
                if (pkt[8] == 0x00)
                {
                    widgets.switch_cell4->set_active(false);
                }
                else
                {
                    widgets.switch_cell4->set_active(true);
                }
                
                widgets.label_voltage_cell4->set_text(receive_voltage(pkt, 9, 13));
                
                if (pkt[14] == 0x00)
                {
                    widgets.switch_cell1->set_active(false);
                }
                else
                {
                    widgets.switch_cell1->set_active(true);
                }
                
                widgets.label_voltage_cell1->set_text(receive_voltage(pkt, 15, 19));
                
                if (pkt[20] == 0x00)
                {
                    widgets.switch_cell5->set_active(false);
                }
                else
                {
                    widgets.switch_cell5->set_active(true);
                }
                
                widgets.label_voltage_cell5->set_text(receive_voltage(pkt, 21, 25));
                
                if (pkt[26] == 0x00)
                {
                    widgets.switch_cell2->set_active(false);
                }
                else
                {
                    widgets.switch_cell2->set_active(true);
                }
                
                widgets.label_voltage_cell2->set_text(receive_voltage(pkt, 27, 31));
                
                if (pkt[32] == 0x00)
                {
                    widgets.switch_cell6->set_active(false);
                }
                else
                {
                    widgets.switch_cell6->set_active(true);
                }
                
                widgets.label_voltage_cell6->set_text(receive_voltage(pkt, 33, 37));
                
                if (pkt[38] == 0x00)
                {
                    widgets.switch_cell3->set_active(false);
                }
                else
                {
                    widgets.switch_cell3->set_active(true);
                }
                
                widgets.label_voltage_cell3->set_text(receive_voltage(pkt, 39, 43));
                
                if (pkt[44] == 0x00)
                {
                    widgets.switch_cell7->set_active(false);
                }
                else
                {
                    widgets.switch_cell7->set_active(true);
                }
                
                widgets.label_voltage_cell7->set_text(receive_voltage(pkt, 45, 49));
                
                // Group 0 current
                widgets.label_current_group0->set_text(receive_voltage(pkt, 51, 55, true));
                
                // Group 1 current
                widgets.label_current_group1->set_text(receive_voltage(pkt, 57, 61, true));
            }
        }
    }
    
	return true;
}

static const char* receive_voltage(std::vector<uint8_t> pkt, unsigned int start, unsigned int end, bool current)
{
    std::string voltage = "";
    for(unsigned int i=start;i<=end;i++)
    {
        switch(pkt[i])
        {
            case 0x00:
                voltage += '0';
                break;
            case 0x01:
                voltage += '1';
                break;
            case 0x02:
                voltage += '2';
                break;
            case 0x03:
                voltage += '3';
                break;
            case 0x04:
                voltage += '4';
                break;
            case 0x05:
                voltage += '5';
                break;
            case 0x06:
                voltage += '6';
                break;
            case 0x07:
                voltage += '7';
                break;
            case 0x08:
                voltage += '8';
                break;
            case 0x09:
                voltage += '9';
                break;
            case 0x2E:
                voltage += '.';
                break;
            default:
                break;
        }
    }
    if (current)
    {
        voltage += " mA";
    }
    else
    {
        voltage += " V";
    }
    
    return voltage.c_str();
}

//! \} End of signals group
