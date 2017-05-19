//
// Coordinates.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Jun 11 10:13:11 2015 SOIDIKI Djamil
// Last update Mon Jun 22 19:35:24 2015 SOIDIKI Djamil
//

#include	"../../includes/GameEngine/Coordinates.hh"

Coordinates::Coordinates(int x, int y) : _x(x), _y(y)
{
}

Coordinates::Coordinates(const Coordinates& c) : _x(c._x), _y(c._y)
{
}

Coordinates::~Coordinates()
{
}

int		Coordinates::getX() const
{
  return (this->_x);
}

int		Coordinates::getY() const
{
  return (this->_y);
}

void		Coordinates::setX(int x)
{
  this->_x = x;
}

void		Coordinates::setY(int y)
{
  this->_y = y;
}

Coordinates&	Coordinates::operator=(const Coordinates& c)
{
  this->_x = c._x;
  this->_y = c._y;
  return (*this);
}

Coordinates	Coordinates::operator+(const Coordinates& c) const
{
  return Coordinates(this->_x + c._x, this->_y + c._y);
}

bool		Coordinates::operator<(const Coordinates& c) const
{
  return (_x != c._x) ? (_x < c._x) : (_y < c._y);
} 
