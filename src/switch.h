/*
 * switch.h
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
 * \file switch.h
 * 
 * \brief Switch class header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 13/06/2017
 * 
 * \defgroup switch Switch
 * \ingroup src
 * \{ 
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include <drivers/gpio.h>

/**
 * \class Switch
 * 
 * \brief 
 */
class Switch: public GPIOAsOutput
{
    public:
        /**
         * \brief Activates the switch.
         * 
         * \return None
         */
        void Activate();
        /**
         * \brief Deactivates the switch.
         * 
         * \return None
         */
        void Deactivate();
};

#endif // SWITCH_H_

//! \} End of switch group
