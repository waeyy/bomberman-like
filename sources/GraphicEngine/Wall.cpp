//
// Box.cpp for character in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:49:44 2015 romain margheriti
// Last update Mon Jun 22 19:39:05 2015 SOIDIKI Djamil
//

#include "../../includes/GraphicEngine/Wall.hh"
#include <iostream>

Wall::Wall(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
  AObject(position, rotation, scale, *new std::string("Wall"))
{
  this->_isBreakable = false;
}

Wall::~Wall()
{
}

std::string const	&Wall::getType() {
  return (_type);
}


bool	Wall::initialize() {
  if (!_model.load("./assets/wall.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
    }
  return (true);
}

void	Wall::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
  _model.draw(shader, getTransformation(), GL_QUADS);
}

