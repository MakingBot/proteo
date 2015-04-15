#ifndef RECORDER_HPP
#define RECORDER_HPP
//!
//! \file Recorder.hpp
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

namespace proteo { namespace core {

//! \class Recorder
//! \brief Simple thread safe logger
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class Recorder : public core::Object
{

public:

    //! \brief Default constructor
    //!
    Recorder(std::string name);

    // ========================================================================
    // => Constantes

    //! \brief Role
    //!
    static const core::ObjRole ORole;

    //! \brief Tag
    //!
    static const core::TagArray OTag;

    //! \brief Property vector
    //!
    static const std::vector<core::Property> Properties;

    // ========================================================================
    // => Object redefinition

    //! \brief FROM Object
    //!
    virtual core::ObjRole objRole() const;

    //! \brief FROM Object
    //!
    virtual const core::TagArray& objTag() const;

    //! \brief FROM Object
    //!
    virtual const std::vector<core::Property>& properties() const;

    // ========================================================================
    // => Recorder


    //! \brief Use std out getter
    //!
    bool useStdOut();

    //! \brief Use std out setter
    //!
    void useStdOut(bool b);

    //! \brief Use log file getter
    //!
    bool useLogFile();

    //! \brief Use log file setter
    //!
    void useLogFile(bool b);


    void rec(const std::string& message);

    //!
    //!
    boost::shared_ptr<Recorder> extern_rec(const std::string message);



    Recorder& operator<<(std::string) {   return *this; }


protected:

    //! \brief Synthesis, true if at least one way of communication is opened
    //!
    bool m_useSynth;

    // mutex
    // std::string buffer  stringstream // buffer



    //! \brief True if the recorder must use std out
    //!
    bool m_useStdOut;


    // Create a global accessor to cout
    // core::SharedCout
    // mutex




    //! \brief True if the recorder must use a file
    //!
    bool m_useLogFile;


    // file stream buffer   ofstream
    // mutex





    //! \brief Update use synthesis
    //!
    inline void updateSynth();


};




/* ============================================================================
 *
 * */
inline void Recorder::updateSynth()
{
    m_useSynth = (m_useStdOut || m_useLogFile);
}



} // core
} // proteo
#endif // RECORDER_HPP

