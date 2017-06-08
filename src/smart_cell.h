/*
 * smart_cell.h
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
 * \file smart_cell.h
 * 
 * \brief Header of the main class of the program.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 01/06/2017
 * 
 * \defgroup smart_cell Smart Cell
 * \ingroup src
 * \{ 
 */

#ifndef SMART_CELL_H_
#define SMART_CELL_H_

#include <drivers/uart.h>

#include "voltmeter.h"
#include "ammeter.h"

/**
 * \class SmartCell
 * 
 * \brief 
 */
class SmartCell
{
        Voltmeter *volt;    /**< . */
        Ammeter *amp;       /**< . */
        UART *uart;         /**< . */
    public:
        /**
         * \brief 
         * 
         * \return None
         */
        SmartCell();
        /**
         * \brief 
         * 
         * \return None
         */
        ~SmartCell();
        /**
         * \brief 
         * 
         * \return 
         */
        void Run();
};

#endif // SMART_CELL_H_

//! \} End of smart_cell group
