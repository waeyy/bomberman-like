//
// Parser.hh for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/includes/common
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sat Jun 20 08:06:45 2015 SOIDIKI Djamil
// Last update Sat Jun 20 09:30:08 2015 SOIDIKI Djamil
//

#ifndef		_PARSER_HH_
# define	_PARSER_HH_

#include	<iostream>
#include	<fstream>
#include	"Exception.hh"

class		Parser {

private:
  std::string	_nameFile;

protected:
  std::ifstream	_file;

public:
  Parser(std::string);
  virtual ~Parser();

  virtual void	parse() = 0;
  std::string	getNameFile() const;
};

#endif		/* _PARSER_HH_ */
