#ifndef VARIANT_HPP
#define VARIANT_HPP
//!
//! \file Variant.hpp
//!
// Copyright 2015 MakingBot
// This file is part of proteo.
//
// proteo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// proteo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with proteo.  If not, see <http://www.gnu.org/licenses/>.

#include <proteo/core/Type.hpp>

namespace proteo { namespace core {

//! \class Variant
//!
class Variant
{
    union BasicType
    {
        bool        b;
        char        c;
        double      d;

        int8_t      i8 ;
        int16_t     i16;
        int32_t     i32;

        void*       p;

        uint8_t     u8 ;
        uint16_t    u16;
        uint32_t    u32;
    };

public:

    //! \brief Default constructor 
    //!
    inline Variant();

    //! \brief Constructor bool
    //!
    inline Variant(bool b);


    template<typename T> Variant(T* p);

    //! \brief Constructor uint8
    //!
    inline Variant(uint8_t u);

    //! \brief Constructor uint16
    //!
    inline Variant(uint16_t u);

    //! \brief Constructor uint32
    //!
    inline Variant(uint32_t u);


    Variant(const std::string& s);


    //! \brief Converter to bool
    //!
    inline bool toBool() const;

    //! \brief Converter to uint8
    //!
    inline uint8_t toUint8() const;

    //! \brief Converter to uint16
    //!
    inline uint16_t toUint16() const;

    //! \brief Converter to uint32
    //!
    inline uint32_t toUint32() const;

protected:

    //! \brief Data meta type
    //!
    MetaType m_mtype;

    //! \brief Data encapsulation
    //!
    BasicType m_bdata;

};


inline Variant::Variant()
{

}


template<typename T>
inline Variant::Variant(T* p)
{
   m_bdata.p = static_cast<void*>(p);
}




/* ============================================================================
 *
 * */
inline Variant::Variant(bool b)
{
    m_mtype = Tbool;
    m_bdata.b = b;
}

/* ============================================================================
 *
 * */
inline Variant::Variant(uint8_t u)
{
    m_mtype = Tuint;
    m_bdata.u8 = u;
}

/* ============================================================================
 *
 * */
inline Variant::Variant(uint16_t u)
{
    m_mtype = Tuint;
    m_bdata.u16 = u;
}

/* ============================================================================
 *
 * */
inline Variant::Variant(uint32_t u)
{
    m_mtype = Tuint;
    m_bdata.u32 = u;
}


inline Variant::Variant(const std::string& s)
{
    m_mtype = Tstring;
    m_bdata.p = static_cast<void*>( new std::string(s) );
}


/* ============================================================================
 *
 * */
inline bool Variant::toBool() const
{
    return m_bdata.b;
}

/* ============================================================================
 *
 * */
inline uint8_t Variant::toUint8() const
{
    return m_bdata.u8;
}

/* ============================================================================
 *
 * */
inline uint16_t Variant::toUint16() const
{
    return m_bdata.u16;
}

/* ============================================================================
 *
 * */
inline uint32_t Variant::toUint32() const
{
    return m_bdata.u32;
}

} // core
} // proteo
#endif // VARIANT_HPP

