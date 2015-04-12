






#include <proteo/core/Object.hpp>

// using namespace boost;
// using namespace boost::python;


using namespace proteo::core;


/* ============================================================================
 *
 * */
Object::Object(std::string name)
    : m_oName(name)
{
     _sgi = new Signals();
}


/* ============================================================================
 *
 * */
const std::string& Object::objName() const
{
    return m_oName;
}

/* ============================================================================
 *
 * */
void Object::setObjName(const std::string& name)
{
    m_oName = name;
}



/* ============================================================================
 *
 * */
bool Object::initiativeConnect(boost::shared_ptr<Object> obj)
{
    connect(obj,true);
}

/* ============================================================================
 *
 * */
bool Object::connect(boost::shared_ptr<Object> obj, bool initiative)
{

    std::cout << "connect" << std::endl;

    connectionHook(obj, initiative);
    
}




/* ============================================================================
 *
 * */
bool Object::connectionHook(boost::shared_ptr<Object> obj, bool initiative)
{
    return true;
}

/* ============================================================================
 *
 * */
bool Object::disconnectionHook(boost::shared_ptr<Object> obj, bool initiative)
{
    return true;
}

/* ============================================================================
 *
 * */
Variant Object::propertyValue(uint8_t id)
{

}

/* ============================================================================
 *
 * */
void Object::setPropertyValue(uint8_t id, const Variant& v)
{

}

/* ============================================================================
 *
 * */
bool Object::isPropertyActive(uint8_t id)
{

}

/* ============================================================================
 *
 * */
bool Object::setPropertyActivity(uint8_t id, bool b)
{

}
