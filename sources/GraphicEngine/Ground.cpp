//
// Ground.cpp for ground in /home/marghe_r/rendu/cpp_bomberman
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Mon Jun 15 15:27:12 2015 romain margheriti
// Last update Mon Jun 22 17:21:38 2015 SOIDIKI Djamil
//

#include "../../includes/GraphicEngine/Ground.hh"
#include <iostream>

Ground::Ground(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : 
  AObject(position, rotation, scale, *new std::string("Ground")) 
{
  this->_isBreakable = false;
}

Ground::~Ground() {
}

bool	Ground::initialize() {
  _speed = 100.0f;
  if (!_model.load("./assets/ground.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
  } 
  return (true);
}

void	Ground::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
   _model.draw(shader, getTransformation(), GL_QUADS);
}

std::string const	&Ground::getType() {
  return (this->_type);
}
