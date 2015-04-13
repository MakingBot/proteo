



//! \class ProteoException
//! \brief Main exception
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ProteoException : public std::exception
{

public:

    ProteoException(std::string message)
        : m_message(message)
    { }

    const char *what() const throw()
    {
        return this->m_message.c_str();
    }

private:

    std::string m_message;

};




