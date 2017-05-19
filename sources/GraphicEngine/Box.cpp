//
// Box.cpp for character in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:49:44 2015 romain margheriti
// Last update Mon Jun 22 17:21:22 2015 SOIDIKI Djamil
//

#include "../../includes/GraphicEngine/Box.hh"
#include <iostream>

Box::Box(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
  AObject(position, rotation, scale, *new std::string("Box"))
{
  this->_isBreakable = false;
}

Box::~Box()
{
}

std::string const	&Box::getType() {
  return (this->_type);
}

bool	Box::initialize() {
  if (!_model.load("./assets/box2.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
    }
  return (true);
}

void	Box::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
  _model.draw(shader, getTransformation(), GL_QUADS);
}

