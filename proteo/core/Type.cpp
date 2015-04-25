

#include "Type.hpp"

using namespace proteo::core;



std::map<std::string, ObjRole> ObjRoleString
{
    { "Rgui"    , ObjRole::Rgui      },
    { "Rmodel"  , ObjRole::Rmodel    }
      
};



ObjRole ObjRoleStringToEnum(std::string role)
{
    return ObjRoleString[role];
}
