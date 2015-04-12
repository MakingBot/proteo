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

    Variant();

    template<typename T> Variant(T* p);


    Variant(uint32_t u);

    Variant(const std::string& s);

protected:


    MetaType m_mtype;

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


}
}

#endif // VARIANT_HPP
