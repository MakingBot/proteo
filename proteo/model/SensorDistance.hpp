#ifndef SENSORDISTANCE_HPP
#define SENSORDISTANCE_HPP

#include <proteo/core/Object.hpp>


#define SENSORDISTANCE_ID_PROPERTY_DISTANCE 0


namespace proteo { namespace model {



class SensorDistance : public core::Object
{

public:

    //! \brief Distance property id
    //!
    static const uint8_t IdPropertyDistance;


    SensorDistance(std::string name);



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



    uint32_t distance()
    {
        return m_distance;
    }


    void setDistance(uint32_t distance)
    {
        m_distance = distance;
    }





protected:

    //! \brief Distance value in mm
    //!
    uint32_t m_distance;

};









} // model
} // proteo
#endif // SENSORDISTANCE_HPP
