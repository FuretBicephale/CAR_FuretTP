#ifndef _FTP_EXCEPTION_H
#define _FTP_EXCEPTION_H

#define THROW(EXCEPTION_TYPE, ...) {\
    EXCEPTION_TYPE exception(__VA_ARGS__);\
    exception.setLocalisation(__FILE__, __LINE__);\
    throw exception;\
    }

#include <string>
#include <stdexcept>

namespace FTP {

///
/// \class Exception
/// \ingroup exception
/// \brief Basic exception
///
class Exception {

public:

    ///
    /// \brief Exception constructor
    ///
    Exception();

    ///
    /// \brief Exception constructor
    /// \param message A message to print
    ///
    Exception(const std::string& message);

    ///
    /// \brief Set error localisation in a file
    /// \param file The file which contains the error
    /// \param line The line which contains the error
    ///
    void setLocalisation(const char* file, int line);

    const std::string& getMessage() const throw();
    const char* getFile() const throw();
    int getLine() const throw();

private:
    const char* _file; ///< The file which contains the error
    int _line; ///< The line which contains the error
    std::string _message; ///< A message to print

};
}

#endif
