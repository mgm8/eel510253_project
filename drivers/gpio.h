/*
 * gpio.h
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
 * \file gpio.h
 * 
 * \brief Arduino Uno GPIO control header.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.0
 * 
 * \date 06/06/2017
 * 
 * \defgroup gpio GPIO
 * \ingroup drivers
 * \{ 
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define GPIO_AS_OUTPUT      0x00
#define GPIO_AS_INPUT       0x01

#define GPIO_DIR_UNDEF      0x02

/**
 * \class GPIO
 * 
 * \brief 
 */
class GPIO
{
        uint8_t pin;            /**< . */
        uint8_t direction;      /**< . */
        /**
         * \brief 
         * 
         * \return None
         */
        void ConfigDir();
    public:
        GPIO();
        /**
         * \brief Class constructor.
         * 
         * \param p
         * 
         * \return None
         */
        GPIO(uint8_t p);
        /**
         * \brief Class constructor.
         * 
         * \param p
         * \param dir
         * 
         * \return None
         */
        GPIO(uint8_t p, uint8_t dir);
        /**
         * \brief Class destructor.
         * 
         * \return None
         */
        ~GPIO();
        /**
         * \brief 
         * 
         * \param p
         * 
         * \return None
         */
        void SetPin(uint8_t p);
        /**
         * \brief 
         * 
         * \return 
         */
        uint8_t GetPin();
        /**
         * \brief 
         * 
         * \param dir
         * 
         * \return None
         */
        void SetDirection(uint8_t dir);
        /**
         * \brief 
         * 
         * \return 
         */
        uint8_t GetDirection();
        /**
         * \brief 
         * 
         * \return None
         */
        void Set();
        /**
         * \brief 
         * 
         * \return None
         */
        void Clear();
        /**
         * \brief 
         * 
         * \return None
         */
        void Toggle();
        /**
         * \brief 
         * 
         * \return 
         */
        bool Read();
};

/**
 * \class GPIOAsOutput
 * 
 * \brief 
 */
class GPIOAsOutput: public GPIO
{
    public:
        /**
         * \brief 
         * 
         * \param p
         * 
         * \return None
         */
        GPIOAsOutput(uint8_t p);
        /**
         * \brief 
         * 
         * \param p
         * \param dir
         * 
         * \return None
         */
        GPIOAsOutput(uint8_t p, uint8_t dir);
};

/**
 * \class GPIOAsInput
 * 
 * \brief 
 */
class GPIOAsInput: public GPIO
{
    public:
        /**
         * \brief 
         * 
         * \param p
         * 
         * \return None
         */
        GPIOAsInput(uint8_t p);
        /**
         * \brief 
         * 
         * \param p
         * \param dir
         * 
         * \return None
         */
        GPIOAsInput(uint8_t p, uint8_t dir);
};

#endif // GPIO_H_

//! \} End of gpio group
