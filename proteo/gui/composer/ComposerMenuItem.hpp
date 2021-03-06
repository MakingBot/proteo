#ifndef COMPOSERMENUITEM_HPP
#define COMPOSERMENUITEM_HPP

#include <QLabel>

//!
//! Menu item of the composer
//!
class ComposerMenuItem : public QLabel
{
    Q_OBJECT

public:
    //!
    //! Default constructor
    //!
    ComposerMenuItem(const QString& block_name, const int hue, QWidget* parent=0);

    //! FROM QWidget
    bool eventFilter(QObject *object, QEvent *event);

protected:

    //! The block name
    const QString _blockName;

    //! FROM QLabel
    virtual void mouseMoveEvent(QMouseEvent* ev);

    //! FROM QLabel
    virtual void mousePressEvent(QMouseEvent* ev);

    //! FROM QLabel
    virtual void mouseReleaseEvent(QMouseEvent* ev);

};

#endif // COMPOSERMENUITEM_HPP