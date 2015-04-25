







#include <QVBoxLayout>

#include "ComposerMenuModules.hpp"


using namespace proteo;
using namespace proteo::gui;

#include <iostream>

/* ============================================================================
 *
 * */
ComposerMenuModules::ComposerMenuModules(QSharedPointer<ComposerParameter> parameter)
    : m_parameter(parameter)
{

    QVBoxLayout* lay = new QVBoxLayout(this);

    for(int i=0 ; i < m_parameter->modules().size() ; i++)
    {
        std::cout << i << " -- " << m_parameter->modules().size() << std::endl;

        ScriptModule& module = m_parameter->modules()[i];

        QSharedPointer<ModuleCheckBox> box( new ModuleCheckBox( module.name(), i ) );

        lay->addWidget(box.data());

        m_checkBoxs << box;


    }

    // m_checkBoxs

}


/* ============================================================================
 *
 * */
void ComposerMenuModules::onStateChange(int state)
{

}

