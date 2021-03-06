//!
//! \file Container.cpp
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

#include "Container.hpp"

using namespace proteo::core;

/* ============================================================================
 *
 * */
Container::Container(std::string name)
    : core::Object(name)
{ }

/* ============================================================================
 *
 * */
const ObjRole Container::ORole = Rtool;

/* ============================================================================
 *
 * */
const Object::TagArray Container::OTag = { 'C', 'N', 'T', 'R' };

/* ============================================================================
 *
 * */
const std::vector<Property> Container::Properties = { };

/* ============================================================================
 *
 * */
ObjRole Container::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Container::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
const std::vector<Property>& Container::properties() const
{
    return Properties;
}
