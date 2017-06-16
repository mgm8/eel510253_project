/*
 * main.cpp
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
 * \file main.cpp
 * 
 * \brief Main file.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 15/06/2017
 * 
 * \defgroup smart_panel_control Smart Panel Control
 * \{
 */

#include <gtkmm.h>

#include "widgets.h"
#include "global_var.h"
#include "signals.h"
#include "error.h"

/**
 * \fn main
 * 
 * \brief The main function.
 * 
 * \param argc Number of arguments passed in on the command line.
 * \param argv A pointer to an array of pointers to the arguments.
 * 
 * \return Returns the error code upon termination.
 */
int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.smart_panel");
    
    // Load the GtkBuilder file and instantiate its widgets:
    auto ref_builder = Gtk::Builder::create();
    try
    {
        ref_builder->add_from_file("../glade/smart_solar_cell.glade");
    }
    catch(const Glib::FileError& ex)
    {
        Error("File error!", ex.what().c_str());
        
        return 1;
    }
    catch(const Glib::MarkupError& ex)
    {
        Error("Markup error!", ex.what().c_str());
        
        return 1;
    }
    catch(const Gtk::BuilderError& ex)
    {
        Error("Builder error!", ex.what().c_str());
        
        return 1;
    }

    ref_builder->get_widget("window1", widgets.main_window);
    if (widgets.main_window)
    {
        // Serial port
        ref_builder->get_widget("entry1", widgets.entry_serial_port);
        ref_builder->get_widget("entry2", widgets.entry_baudrate);
        
        ref_builder->get_widget("togglebutton1", widgets.togglebutton_open_close_port);
        if (widgets.togglebutton_open_close_port)
        {
            widgets.togglebutton_open_close_port->signal_toggled().connect(sigc::ptr_fun(on_togglebutton1_toggled));
        }
        
        // Cells switches
        ref_builder->get_widget("switch1", widgets.switch_cell0);
        ref_builder->get_widget("switch2", widgets.switch_cell1);
        ref_builder->get_widget("switch3", widgets.switch_cell2);
        ref_builder->get_widget("switch4", widgets.switch_cell3);
        ref_builder->get_widget("switch5", widgets.switch_cell4);
        ref_builder->get_widget("switch6", widgets.switch_cell5);
        ref_builder->get_widget("switch7", widgets.switch_cell6);
        ref_builder->get_widget("switch8", widgets.switch_cell7);
        
        // Cells voltages
        ref_builder->get_widget("label7", widgets.label_voltage_cell0);
        ref_builder->get_widget("label5", widgets.label_voltage_cell1);
        ref_builder->get_widget("label6", widgets.label_voltage_cell2);
        ref_builder->get_widget("label8", widgets.label_voltage_cell3);
        ref_builder->get_widget("label9", widgets.label_voltage_cell4);
        ref_builder->get_widget("label10", widgets.label_voltage_cell5);
        ref_builder->get_widget("label11", widgets.label_voltage_cell6);
        ref_builder->get_widget("label12", widgets.label_voltage_cell7);
        
        // Groups current
        ref_builder->get_widget("label13", widgets.label_current_group0);
        ref_builder->get_widget("label14", widgets.label_current_group1);
        
        ref_builder->get_widget("checkbutton1", widgets.checkbutton_manual_control);
        
        g_timeout_add(DATA_RECEPTION_SAMPLE_RATE, (GSourceFunc)timer_handler, (gpointer)widgets.main_window);
        timer_handler();

        app->run(*widgets.main_window);
    }

    delete widgets.main_window;
    
    return 0;
}

//! \} End of smart_panel_control group
