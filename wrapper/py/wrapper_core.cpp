

#include <boost/python.hpp>

#include <proteo/core/Object.hpp>

/* ============================================================================
 *
 * */
void export_core()
{
    namespace bp = boost::python;
    namespace pc = proteo::core;

    // Map the core namespace to a sub-module
    // Make "from proteo.core import ..." work
    bp::object core_module(bp::handle<>(bp::borrowed(PyImport_AddModule("proteo.core"))));
    // Make "from proteo import core" work
    bp::scope().attr("core") = core_module;
    // Set the current scope to the new sub-module
    bp::scope core_scope = core_module;


    bp::class_<pc::Object, boost::noncopyable>("Object", bp::no_init)
            
        .def("connect", &pc::Object::initiativeConnect)
        
        .add_property("objName", &pc::Object::objName, &pc::Object::setObjName);
        ;


}

