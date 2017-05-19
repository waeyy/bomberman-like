//
// Exception.hh for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/includes
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Jun 11 10:03:43 2015 SOIDIKI Djamil
// Last update Thu Jun 18 15:52:30 2015 SOIDIKI Djamil
//

#ifndef		_EXCEPTION_HH_
# define	_EXCEPTION_HH_

#include	<iostream>
#include	<sstream>
#include	<exception>
#include	<cerrno>
#include	<cstring>

#define		USAGE_ERROR	0
#define		CLASSIC_ERROR	1
#define		NO_ERRNO	-42

using		std::string;
using		std::endl;

class		Exception : public std::exception {

protected:
  string	_message;

public:
  Exception(int, int, const string&, const string&);
  virtual ~Exception() throw();

  virtual const char * what() const throw();
};

#endif		/* _EXCEPTION_HH_ */
