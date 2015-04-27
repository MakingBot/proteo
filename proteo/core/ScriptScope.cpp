//!
//! \file ScriptScope.cpp
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


#include "ScriptScope.hpp"

using namespace proteo::core;


/* ============================================================================
 *
 * */
std::string ScriptScope::toPathChain() const
{
    std::string path_chain;
    for(const std::string& scope : m_scopeChain)
    {
        path_chain += scope;
        #ifdef _WIN32
        path_chain += '/';
        #else
        path_chain += '/';
        #endif
        // #include <boost/filesystem.hpp>
        // std::cout << boost::filesystem::path::preferred_separator 
    }

    std::cout << "== " << path_chain << std::endl;
    
    if(!path_chain.empty())
    {
        path_chain.pop_back();
    }
    return path_chain;
}

/* ============================================================================
 *
 * */
std::string ScriptScope::toDotChain() const
{
    std::string dot_chain;
    for(const std::string& scope : m_scopeChain)
    {
        dot_chain += scope;
        dot_chain += '.';
    }
    dot_chain.pop_back();
    return dot_chain;
}
