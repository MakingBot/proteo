



#include <proteo/model/SensorDistance.hpp>



using namespace proteo::core;
using namespace proteo::model;


const uint8_t SensorDistance::IdPropertyDistance = SENSORDISTANCE_ID_PROPERTY_DISTANCE;




SensorDistance::SensorDistance(std::string name)
    : core::Object(name)
{

}



/* ============================================================================
 *
 * */
const ObjRole SensorDistance::ORole = Rgui;

/* ============================================================================
 *
 * */
const TagArray SensorDistance::OTag = { 'S', 'N', 'S', 'R', 'D', 'I', 'S', 'T' };

/* ============================================================================
 *
 * */
const std::vector<Property> SensorDistance::Properties = {
   // Property()
};



/* ============================================================================
 *
 * */
ObjRole SensorDistance::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const TagArray& SensorDistance::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
const std::vector<Property>& SensorDistance::properties() const
{
    return Properties;
}



