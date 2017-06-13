/*
 * reading.h
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
 * \file reading.h
 * 
 * \brief Reading struct header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 13/06/2017
 * 
 * \defgroup reading Reading
 * \ingroup src
 * \{ 
 */

#ifndef READING_H_
#define READING_H_

/**
 * \struct Reading
 * 
 * \brief A struct to store the readings from a given channel.
 */
struct Reading
{
    double r0;      /**< . */
    double r1;      /**< . */
    /**
     * \brief Struct constructor;
     * 
     * \return None
     */
    Reading()
    {
        
    }
    /**
     * \brief Struct constructor.
     * 
     * \param a is the value of the first reading.
     * \param b is the value of the seconds reading.
     * 
     * \return None
     */
    Reading(double a, double b)
    {
        r0 = a;
        r1 = b;
    }
    /**
     * \brief Struct operator =
     * 
     * \param R is another Reading object.
     * 
     * \return A pointer to this struct.
     */
    void operator = (Reading R)
    {
        r0 = R.r0;
        r1 = R.r1;
    }
};

#endif // READING_H_

//! \} End of reading group
