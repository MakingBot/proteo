

#include <boost/python.hpp>

#include <proteo/model/SensorDistance.hpp>


/* ============================================================================
 *
 * */
void export_model()
{
    namespace bp = boost::python;
    namespace pc = proteo::core;
    namespace pm = proteo::model;
        

    // Map the model namespace to a sub-module
    // Make "from proteo.model import ..." work
    bp::object model_module(bp::handle<>(bp::borrowed(PyImport_AddModule("proteo.model"))));
    // Make "from proteo import model" work
    bp::scope().attr("model") = model_module;
    // Set the current scope to the new sub-module
    bp::scope model_scope = model_module;

    // === Export

    
    bp::class_<pm::SensorDistance, bp::bases<pc::Object> >("SensorDistance", bp::init<std::string>())
        ;


}
