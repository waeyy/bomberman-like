//
// Options.cpp for Options.cpp in /home/taulei_c/rendu/PAV/cpp_bomberman/src
// 
// Made by charles tauleigne
// Login   <taulei_c@epitech.net>
// 
// Started on  Fri May 22 18:49:42 2015 charles tauleigne
// Last update Tue Jun 23 15:25:45 2015 SOIDIKI Djamil
//

#include	"../../includes/GameEngine/Options.hh"

Options::Options(unsigned int nb_players, unsigned int nb_ia, 
		 unsigned int height_map,
		 unsigned int width_map, bool isRandom) : _nb_players(nb_players),
							  _nb_ia(nb_ia),
							  _height_map(height_map),
							  _width_map(width_map),
							  _randommap(isRandom)
							  
{
}

Options::~Options()
{
}

void		Options::setNbPlayers(unsigned int nb_players)
{
  this->_nb_players = nb_players;
}

void		Options::setNbIa(unsigned int nb_ia)
{
  this->_nb_ia = nb_ia;
}

void		Options::setIALevel(unsigned int ia_level)
{
  this->_ia_level = ia_level;
}

void		Options::setHeightMap(unsigned int height_map)
{
  this->_height_map = height_map;
}

void		Options::setWidthMap(unsigned int width_map)
{
  this->_width_map = width_map;
}

void		Options::setMap(std::string map)
{
  this->_map = map;
}

void		Options::setRandommap(bool randommap)
{
  this->_randommap = randommap;
}

unsigned int	Options::getNbPlayers() const
{
  return (this->_nb_players);
}

unsigned int	Options::getNbIa() const
{
  return (this->_nb_ia);
}

unsigned int	Options::getIALevel() const
{
  return (this->_ia_level);
}

unsigned int	Options::getHeightMap() const
{
  return (this->_height_map);
}

unsigned int	Options::getWidthMap() const
{
  return (this->_width_map);
}

std::string	Options::getMap() const
{
  return (this->_map);
}

bool		Options::getRandommap() const
{
  return (this->_randommap);
}
