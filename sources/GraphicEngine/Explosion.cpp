//
// Explosion.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources/GraphicEngine
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sat Jun 20 18:25:59 2015 SOIDIKI Djamil
// Last update Mon Jun 22 17:55:03 2015 SOIDIKI Djamil
//

#include "../../includes/GraphicEngine/Explosion.hh"
#include <iostream>

float timer_explosion = 0;

Explosion::Explosion(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale,
		     std::vector<AObject*>& objects) :
  AObject(position, rotation, scale, *new std::string("Explosion")), 
  _listObjects(objects)
{
  this->_id = objects.size();
}

Explosion::~Explosion()
{
}

std::string const &Explosion::getType() {
  return (this->_type);
}

bool	Explosion::initialize() {
  if (!_model.load("./assets/explosion.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
    }
  return (true);
}

void    Explosion::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) input;

  timer_explosion += clock.getElapsed();
  if ( ((timer_explosion / 60) * 10) > 0.2)
    {
      timer_explosion = 0;
      this->removeExplosion();
    }
}

void	Explosion::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
  _model.draw(shader, getTransformation(), GL_QUADS);
}


void	Explosion::removeExplosion()
{
  this->_hasToBeRemove = true;
}
