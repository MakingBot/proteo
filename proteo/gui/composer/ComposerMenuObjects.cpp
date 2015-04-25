





#include "ComposerMenuObjects.hpp"


using namespace proteo;
using namespace proteo::gui;


#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;




ComposerMenuObjects::ComposerMenuObjects(QSharedPointer<ComposerParameter> parameter)
{

    // call<std::string>(callable_object, a1, a2... aN);
    
    // namespace python = boost::python;
    // python::object locals(python::borrowed(PyEval_GetLocals()));

    // Inject an instance of Y into the frame's locals as variable 'y'.
    // Boost.Python will handle the conversion of C++ Y to Python Y.
    //object n = locals.attr("gui.proteo_gui_objects")();
    

    // python::dict globals(python::borrowed(PyEval_GetGlobals()));
    // object f = globals.get("gui");

    // object n = f.attr("proteo_gui_objects")();
    

    // //["y"] = Y();

    // std::string res( str(n) ) ;



    // std::cout << res << std::endl;

    // Retrieve the main module.
    object main = import("__main__");
      
    // Retrieve the main module's namespace
    object global(main.attr("__dict__"));

    // Define greet function in Python.
    object result = eval("proteo_gui_objects()", global, global);

    //exec
    //extract<std::string> e_type_pstr(type_pstr);

    char * c_str = extract<char *>(result);
    std::string str(c_str);


    std::cout << str << std::endl; 
}


void ComposerMenuObjects::onStateChange(int state)
{

}

