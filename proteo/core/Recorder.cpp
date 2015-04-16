//!
//! \file Recorder.cpp
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

#include "Recorder.hpp"

using namespace proteo::core;

/* ============================================================================
 *
 * */
Recorder::Recorder(std::string name)
    : core::Object(name)
{ }

/* ============================================================================
 *
 * */
const ObjRole Recorder::ORole = Rtool;

/* ============================================================================
 *
 * */
const TagArray Recorder::OTag = { 'R', 'E', 'C', 'O' };

/* ============================================================================
 *
 * */
const std::vector<Property> Recorder::Properties = {
    // Property(IdPropertyDistance, "distance", Tuint)
};

/* ============================================================================
 *
 * */
boost::shared_ptr<Recorder> Recorder::extern_rec(const std::string message)
{
    this->rec(message);
    return std::dynamic_pointer_cast<Recorder>(Object::shared_from_this());
}

/* ============================================================================
 *
 * */
ObjRole Recorder::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const TagArray& Recorder::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
bool Recorder::useStdOut()
{
    return m_useStdOut;
}

/* ============================================================================
 *
 * */
void Recorder::useStdOut(bool b)
{
    m_useStdOut = b;
}

/* ============================================================================
 *
 * */
bool Recorder::useLogFile()
{
    return m_useLogFile;
}

/* ============================================================================
 *
 * */
void Recorder::useLogFile(bool b)
{
    m_useLogFile = b;
}

