//!wrapper_core_codestream.cpp
//! \file wrapper_core_codestream.cpp
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

#include <proteo/core/Object.hpp>
#include <proteo/core/CodeStream.hpp>

using namespace proteo::core;

/* ============================================================================
 *
 * */
CodeStream& operator<< (CodeStream& cs, bool a)
{
    if(a)
    {
        cs.currentStream() << "True";
    }
    else
    {
        cs.currentStream() << "False";
    }
    return cs;
}

/* ============================================================================
 *
 * */
CodeStream& operator<< (CodeStream& cs, const char* s)
{
    cs.currentStream() << s;

    return cs;
}

/* ============================================================================
 *
 * */
CodeStream& operator<< (CodeStream& cs, const std::string& s)
{
    cs.currentStream() << s;

    return cs;
}


/* ============================================================================
 *
 * */
CodeStream& operator<< (CodeStream& cs, boost::shared_ptr<Object> o)
{
    cs.setCurrentSection(CodeStream::SectionCreation);
    cs << o->objName() << " = " << o->objType() << "('" << o->objName() << "')" << "\n";


    cs.setCurrentSection(CodeStream::SectionConnection);
    if( o->nbObjChilds() > 0  )
    {
        std::map<std::string, boost::shared_ptr<Object> >::iterator child;
        for (child=o->objChilds().begin(); child!=o->objChilds().end(); ++child)
        {
            cs << child->second;
        }
    }


    return cs;
}



/* ============================================================================
 *
 * */
CodeStream& operator<< (CodeStream& cs, const ScriptModule& m)
{
    if(m.isImported())
    {
        cs.setCurrentSection(CodeStream::SectionImport);
        cs << "from " << m.toDotChain() << " import * \n";
    }
    return cs;
}

/* ============================================================================
 *
 * */
CodeStream& operator<< (CodeStream& cs, const std::list<ScriptModule>& ms)
{
    for(const ScriptModule &m : ms)
    {
        cs << m;
    }
    return cs;
}
