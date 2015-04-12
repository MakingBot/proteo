#ifndef SPYWIDGETHEADER_HPP
#define SPYWIDGETHEADER_HPP


#include "DoubleLabel.hpp"

namespace proteo { namespace gui {


class Spy;

//!
//! Header of the spy widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class SpyWidgetHeader : public QWidget
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    explicit SpyWidgetHeader(Spy* spy);

    //! FROM QWidget
    void paintEvent(QPaintEvent *event);


public slots:

    //! When the spied change
    void onSpiedObjChange();

    //! Update property values
    void updateProperties();

protected:

    //! Label for name 
    QLabel m_labelName;

    //! Tag for the type name
    DoubleLabel m_labelTag;

    //! Tag for version
    DoubleLabel m_labelRole;

    //! Label for father name
    DoubleLabel m_labelParent;

    //! Label for number of sons
    DoubleLabel m_labelChildNb;

    //! Label for number of connections
    DoubleLabel m_labelConnNb;




    // 3 buttons (radio)
    // no log
    // enbale log     
    // enable verbose 




    //! \brief Pointer on the parent object
    //!
    Spy* m_spy;

    //! \brief Function that change text and color of the name label header
    //!
    void updateLabelName(const std::string& name, quint32 color);


};


} // gui
} // proteo
#endif // SPYWIDGETHEADER_HPP
