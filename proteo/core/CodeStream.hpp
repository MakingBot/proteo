#ifndef CODESTREAM_HPP
#define CODESTREAM_HPP
//!
//! \file CodeStream.hpp
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

#include <string>
#include <sstream>
#include <iostream>

#include <boost/shared_ptr.hpp>

#include "ScriptModule.hpp"


namespace proteo { namespace core {

class Object;

class CodeStream
{

public:

    enum Section
    {
        SectionImport      ,
        SectionCreation    ,
        SectionConnection  ,
        SectionActivation  
    };


    CodeStream();


    void setCurrentSection(Section sec)
    {
        m_currentSection = sec;
    }


    std::stringstream& currentStream()
    {
        return stream(m_currentSection);
    }    

    std::stringstream& stream(Section section)
    {
        switch(section)
        {
            case SectionImport     : return m_sectionImport;     break;  
            case SectionCreation   : return m_sectionCreation;   break;
            case SectionConnection : return m_sectionConnection; break;
            case SectionActivation : return m_sectionActivation; break; 
        }
    }


    std::string code();

protected:

    Section m_currentSection;

    std::stringstream m_sectionImport;    
    std::stringstream m_sectionCreation;   
    std::stringstream m_sectionConnection;
    std::stringstream m_sectionActivation;

};

} // core
} // proteo

//! \brief Append the code for a bool
//!
proteo::core::CodeStream& operator<< (proteo::core::CodeStream& cs, bool a);


proteo::core::CodeStream& operator<< (proteo::core::CodeStream& cs, const char* s);

proteo::core::CodeStream& operator<< (proteo::core::CodeStream& cs, const std::string& s);

proteo::core::CodeStream& operator<< (proteo::core::CodeStream& cs, boost::shared_ptr<proteo::core::Object> o);

proteo::core::CodeStream& operator<< (proteo::core::CodeStream& cs, const proteo::core::ScriptModule& m);

proteo::core::CodeStream& operator<< (proteo::core::CodeStream& cs, const std::list<proteo::core::ScriptModule>& ms);

#endif // CODESTREAM_HPP
