//
// Exception.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Jun 11 10:03:32 2015 SOIDIKI Djamil
// Last update Thu Jun 18 15:53:10 2015 SOIDIKI Djamil
//

#include	"../../includes/common/Exception.hh"

Exception::Exception(int _errno, int line, const string& file,
		     const string& _message)
{
  std::ostringstream	oss;

  if (_errno)
    {
      oss << "[ERROR] (" << file << ":" << line << ")" << endl 
	  << _message << ": " << strerror(_errno);
    }
  else if (_errno == NO_ERRNO)
    {
      oss << "[ERROR] (" << file << ":" << line << ")" << endl 
	  << _message;
    }
  else
    oss << _message;
  this->_message = oss.str(); 
}

Exception::~Exception() throw()
{
}

const char*	Exception::what() const throw()
{
  return (this->_message.c_str());
}
