//
// Parser.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources/common
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sat Jun 20 08:25:09 2015 SOIDIKI Djamil
// Last update Sat Jun 20 09:49:50 2015 SOIDIKI Djamil
//

#include	"../../includes/common/Parser.hh"

Parser::Parser(std::string namefile) : _nameFile(namefile)
{
  std::size_t	found = namefile.find(".xml");

  this->_file.open(namefile.c_str());
  if (found == std::string::npos)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "must provide a xml file");
  if (!this->_file)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "xml file doesn't exist");
}

Parser::~Parser()
{
  this->_file.close();
}

std::string	Parser::getNameFile() const
{
  return (this->_nameFile);
}
