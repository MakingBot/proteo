#ifndef TYPE_HPP
#define TYPE_HPP

#include <stdint.h>

#include <map>
#include <bitset>
#include <vector>
#include <string>
#include <iostream>

#include <boost/bimap.hpp>
#include <boost/signals2.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>


#define PROTEO_UNUSED(x) (void)x;


namespace proteo { namespace core {


enum MetaType
{
    Tint,
    Tuint,
    Tbool,
    Tenum,

    Tstring,

    Treserved = 0xFFFFFFFF
};



enum ObjRole
{
    Rgui        = 0x4CAF50,
    Rmodel      = 0x2196F3,
    Rinterface  = 0xF44336
};



enum ObjState
{
    Sok ,
    Shs
};



}
}


#endif // TYPE_HPP
