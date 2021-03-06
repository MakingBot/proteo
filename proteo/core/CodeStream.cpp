//!
//! \file CodeStream.cpp
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

#include "CodeStream.hpp"

using namespace proteo::core;

/* ============================================================================
 *
 * */
CodeStream::CodeStream()
    : m_currentSection(SectionImport)
{ }


/* ============================================================================
 *
 * */
std::string CodeStream::code()
{
    std::stringstream code;

    code << m_sectionImport.str();
    code << "\n"; 
    code << m_sectionCreation.str();
    code << "\n"; 
    code << m_sectionConnection.str();
    code << "\n"; 
    code << m_sectionActivation.str();
    code << "\n";

    return code.str();
}

