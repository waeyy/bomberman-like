//
// BoxBreakable.cpp for  in /home/soidik_d/Downloads/old-june/Bomberman-romain/sources/GraphicEngine
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Jun 22 16:25:28 2015 SOIDIKI Djamil
// Last update Mon Jun 22 19:25:40 2015 SOIDIKI Djamil
//

#include "../../includes/GraphicEngine/BoxBreakable.hh"
#include <iostream>

BoxBreakable::BoxBreakable(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
  AObject(position, rotation, scale, *new std::string("BoxBreakable"))
{
  this->_isBreakable = true;
}

BoxBreakable::~BoxBreakable()
{
}

std::string const	&BoxBreakable::getType() {
  return (this->_type);
}

bool	BoxBreakable::initialize() {
  if (!_model.load("./assets/box.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
    }
  return (true);
}

void	BoxBreakable::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
  _model.draw(shader, getTransformation(), GL_QUADS);
}

