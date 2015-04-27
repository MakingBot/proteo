







#include <QVBoxLayout>

#include "ComposerMenuModules.hpp"


using namespace proteo;
using namespace proteo::gui;
using namespace proteo::core;

#include <iostream>

/* ============================================================================
 *
 * */
ComposerMenuModules::ComposerMenuModules(QSharedPointer<ComposerParameter> parameter)
    : m_parameter(parameter)
{
    // Create the layout
    QVBoxLayout* lay = new QVBoxLayout(this);

    // Refresh
    refreshModuleList();
}

/* ============================================================================
 *
 * */
void ComposerMenuModules::refreshModuleList()
{
    int i=0;
    for (std::list<core::ScriptModule>::iterator module = m_parameter->modules().begin() ; module != m_parameter->modules().end() ; ++module)
    {

        // Create the associated checkbox
        QSharedPointer<ModuleCheckBox> box( new ModuleCheckBox((*module).toDotChain().c_str(),i) );

        // Connect the box signal
        connect(box.data()  , &ModuleCheckBox::stateChanged       ,
                this        , &ComposerMenuModules::onStateChange );

        // Append it into the layout
        ((QVBoxLayout*)layout())->addWidget(box.data());
        m_checkBoxs << box;

        i++;
    }
}

/* ============================================================================
 *
 * */
void ComposerMenuModules::onStateChange(int state)
{
    // Get the sender widget
    ModuleCheckBox* box = qobject_cast<ModuleCheckBox*>(sender());
    if(!box)
    {
        return;
    }

    // Get the module and set apply the new value
    std::list<core::ScriptModule>::iterator module = m_parameter->modules().begin();
    for(int i=0; i<box->index ; i++)
        module++;


    switch(state)
    {
        case Qt::Unchecked:
            (*module).setImported(false);
            m_parameter->signalParamModification();
            break;

        case Qt::Checked:
            (*module).setImported(true);
            m_parameter->signalParamModification();
            break;

        case Qt::PartiallyChecked:
        default:
            break;
    }
}

