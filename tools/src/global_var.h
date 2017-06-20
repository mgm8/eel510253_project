/*
 * global_var.h
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
 * \file global_var.h
 * 
 * \brief Global variables header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 07/05/2017
 * 
 * \defgroup global_var Global variables
 * \ingroup smart_panel_control
 * \{
 */

#ifndef GLOBAL_VAR_H_
#define GLOBAL_VAR_H_

#include <drivers/uart.h>

#include "widgets.h"

#define DATA_RECEPTION_SAMPLE_RATE  500

/**
 * \var 
 * 
 * \brief 
 */
extern Widgets widgets;

/**
 * \var 
 * 
 * \brief 
 */
extern UART uart;

#endif // GLOBAL_VAR_H_

//! \} End of gloval_var group
