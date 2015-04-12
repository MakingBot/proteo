




#include <proteo/gui/Spy.hpp>
#include <proteo/gui/spy/SpyWidget.hpp>

using namespace proteo;
using namespace proteo::gui;
using namespace proteo::core;

/* ============================================================================
 *
 * */
Spy::Spy(std::string name)
    : Object(name)
    , m_widget(new SpyWidget(this))
{



    
    m_widget->show();
}


/* ============================================================================
 *
 * */
const ObjRole Spy::ORole = Rgui;

/* ============================================================================
 *
 * */
const TagArray Spy::OTag = { '_', '_', 'S', 'P', 'Y', '_', '_', '_' };

/* ============================================================================
 *
 * */
const std::vector<Property> Spy::Properties = {
   // Property()
};



/* ============================================================================
 *
 * */
ObjRole Spy::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const TagArray& Spy::objTag() const
{

}

/* ============================================================================
 *
 * */
bool Spy::connectionHook(boost::shared_ptr<Object> obj, bool initiative)
{
    m_spied = obj;
}

/* ============================================================================
 *
 * */
const std::vector<Property>& Spy::properties() const
{
    return Properties;
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Spy::spiedObj()
{
    return m_spied;
}


