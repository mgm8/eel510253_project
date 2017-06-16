/*
 * widgets.h
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
 * \file widgets.h
 * 
 * \brief Widgets struct.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 15/06/2017
 * 
 * \defgroup widgets Widgets
 * \ingroup smart_panel_control
 * \{
 */

#ifndef WIDGETS_H_
#define WIDGETS_H_

#include <gtkmm.h>

/**
 * \struct Widgets
 * 
 * \brief 
 */
struct Widgets
{
    Gtk::Window                     *main_window;
    
    Gtk::Entry                      *entry_serial_port;
    Gtk::Entry                      *entry_baudrate;
    Gtk::ToggleButton               *togglebutton_open_close_port;
    
    Gtk::Switch                     *switch_cell0;
    Gtk::Switch                     *switch_cell1;
    Gtk::Switch                     *switch_cell2;
    Gtk::Switch                     *switch_cell3;
    Gtk::Switch                     *switch_cell4;
    Gtk::Switch                     *switch_cell5;
    Gtk::Switch                     *switch_cell6;
    Gtk::Switch                     *switch_cell7;
    
    Gtk::Label                      *label_voltage_cell0;
    Gtk::Label                      *label_voltage_cell1;
    Gtk::Label                      *label_voltage_cell2;
    Gtk::Label                      *label_voltage_cell3;
    Gtk::Label                      *label_voltage_cell4;
    Gtk::Label                      *label_voltage_cell5;
    Gtk::Label                      *label_voltage_cell6;
    Gtk::Label                      *label_voltage_cell7;
    
    Gtk::Label                      *label_current_group0;
    Gtk::Label                      *label_current_group1;
    
    Gtk::CheckButton                *checkbutton_manual_control;
};

#endif // WIDGETS_H_

//! \} End of widgets group
