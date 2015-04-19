

#include <boost/python.hpp>



//! \brief Export core module
//!
void export_core();

//! \brief Export model module
//!
void export_model();

//! \brief Export gui module
//!
void export_gui();

//! \brief Export brain module
//!
void export_brain();

/* ============================================================================
 *
 * */
BOOST_PYTHON_MODULE(proteo)
{
    namespace bp = boost::python;

    // Specify that this module is actually a package
    bp::object package = bp::scope();
    package.attr("__path__") = "proteo";

    // Export modules
    export_core();
    export_model();
    export_gui();
    export_brain();
    
}

