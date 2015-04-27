#ifndef SCRIPTSCOPE_HPP
#define SCRIPTSCOPE_HPP
//!
//! \file ScriptScope.hpp
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

#include <list>
#include <string>
#include <iostream>

namespace proteo { namespace core {

//! \class ScriptScope
//! \brief 
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ScriptScope
{

public:

    //! \brief Default constructor
    //!
    inline ScriptScope(const std::string& base = "");

    //! \brief Scope name list to path chain 'path/to/scope'
    //!
    std::string toPathChain() const;

    //! \brief Scope name list to dot chain 'path.to.scope'
    //!
    std::string toDotChain() const;

protected:

    //! \brief List of scope namespace
    //!
    std::list<std::string> m_scopeChain;

};

/* ============================================================================
 *
 * */
inline ScriptScope::ScriptScope(const std::string& base)
{
    std::string s(base);
    size_t pos = 0;
    std::string token;
    std::string delimiter = ".";

    std::cout << "in " << std::endl;
    
    while( (pos = s.find(delimiter)) != std::string::npos )
    {
        token = s.substr(0, pos);
        m_scopeChain.push_back(token);
        s.erase(0, pos + delimiter.length());

        std::cout << token << std::endl;
    }
    m_scopeChain.push_back(s);


}

} // core
} // proteo
#endif // SCRIPTSCOPE_HPP

