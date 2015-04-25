





#include "ComposerMenuObjects.hpp"


#include <QVBoxLayout>

using namespace proteo;
using namespace proteo::gui;


#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;



/* ============================================================================
 *
 * */
ComposerMenuObjects::ComposerMenuObjects(QSharedPointer<ComposerParameter> parameter)
    : m_parameter(parameter)
{
    // Connect the box signal
    connect(m_parameter.data()  , &ComposerParameter::moduleListModified    ,
            this                , &ComposerMenuObjects::onModuleListModified );

    // Create the layout
    new QVBoxLayout(this);

    // 
    refreshUi();
}


/* ============================================================================
 *
 * */
void ComposerMenuObjects::refreshUi()
{
    // First ui must be reset
    destroyUi();

    // Extract items for modules
    for(int i=0 ; i < m_parameter->modules().size() ; i++)
    {
        ScriptModule& module = m_parameter->modules()[i];

        extractObjectFromModule(module);
    }
}

/* ============================================================================
 *
 * */
void ComposerMenuObjects::onStateChange(int state)
{

}

/* ============================================================================
 *
 * */
void ComposerMenuObjects::onModuleListModified()
{
    refreshUi();
}

/* ============================================================================
 *
 * */
void ComposerMenuObjects::destroyUi()
{
    m_items.clear();
}

/* ============================================================================
 *
 * */
void ComposerMenuObjects::extractObjectFromModule(ScriptModule& module)
{
    // Check if the module is imported
    if( !module.isImported() )
    {
        return;
    }

    // Retrieve the main module.
    object main = import("__main__");

    // Retrieve the main module's namespace
    object global(main.attr("__dict__"));

    // 
    QString object_function = QString("proteo_") + module.name() + QString("_objects()");

    // Define greet function in Python.
    object result = eval(object_function.toStdString().c_str(), global, global);

    //
    char * list_c_str = extract<char *>(result);
    QString list_qstr(list_c_str);

    std::cout << list_c_str << std::endl;

    //
    QStringList objects = list_qstr.split(';');

    std::cout << objects.size() << std::endl;

    //
    foreach(const QString& obj, objects)
    {
        const QStringList tmp = obj.split('-');
        const QString name = tmp[0];
        const QString role = tmp[1];

        
        QSharedPointer<ComposerMenuItem> item = QSharedPointer<ComposerMenuItem>( new ComposerMenuItem(name, 33) );

        ((QVBoxLayout*)layout())->addWidget(item.data());

        m_items.append( item  );
    }
}

