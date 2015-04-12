#ifndef SPY_HPP
#define SPY_HPP



#include <proteo/core/Object.hpp>






namespace proteo { namespace gui {
   
class SpyWidget;
 

//! \class Spy
//!
class Spy : public core::Object
{

public:

    //! \brief Default constructor
    //!
    Spy(std::string name);

    // ========================================================================
    // => Constantes

    //! \brief Role
    //!
    static const core::ObjRole ORole;

    //! \brief Tag
    //!
    static const core::TagArray OTag;

    //! \brief Property vector
    //!
    static const std::vector<core::Property> Properties;

    // ========================================================================
    // => Object redefinition

    //! \brief FROM Object
    //!
    virtual core::ObjRole objRole() const;

    //! \brief FROM Object
    //!
    virtual const core::TagArray& objTag() const;


    //! \brief FROM Object
    //!
    bool connectionHook(boost::shared_ptr<Object> obj, bool initiative);


    virtual const std::vector<core::Property>& properties() const;
   


    // ========================================================================
    // => Spy



    boost::shared_ptr<Object> spiedObj();







protected:

    std::string m_name;

    boost::shared_ptr<Object> m_spied;

    boost::shared_ptr<SpyWidget> m_widget;
 

};

// ostream& operator<<(ostream&, Spy);







}
}
#endif // SPY_HPP
