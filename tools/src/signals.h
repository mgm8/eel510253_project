/*
 * signals.h
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
 * \file signals.h
 * 
 * \brief Signals handlers.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 07/05/2017
 * 
 * \defgroup signals Signals handlers
 * \ingroup smart_cell_control
 * \{
 */

#ifndef SIGNALS_H_
#define SIGNALS_H_

#include <vector>
#include <stdint.h>

/**
 * \fn on_togglebutton1_toggled
 * 
 * \brief 
 * 
 * \return None
 */
void on_togglebutton1_toggled();

/**
 * \fn timer_handler
 * 
 * \brief 
 * 
 * \return 
 */
bool timer_handler();

/**
 * \fn receive_voltage
 * 
 * \brief 
 * 
 * \param pkt
 * \param start
 * \param end
 * 
 * \return 
 */
static const char* receive_voltage(std::vector<uint8_t> pkt, unsigned int start, unsigned int end);

#endif // SIGNALS_H_

//! \} End of signals group
