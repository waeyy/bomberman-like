//
// Bomb.cpp for Bomb in /home/marghe_r/rendu/cpp_bomberman
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Thu Jun 18 02:37:19 2015 romain margheriti
// Last update Tue Jun 23 12:48:32 2015 SOIDIKI Djamil
//

#include "../../includes/common/Exception.hh"
#include "../../includes/GraphicEngine/Bomb.hh"
#include "../../includes/GraphicEngine/Explosion.hh"
#include "../../includes/GraphicEngine/Ground.hh"
#include <iostream>

float timer_bomb = 0;

Bomb::Bomb(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale,
	   std::vector<AObject*>& objects, 
	   std::multimap<Coordinates, AObject*>& map) : 
  AObject(position, rotation, scale, *new std::string("Bomb")), 
  _listObjects(objects),
  _map(map)
{
  this->_touchPlayer = false;
}

Bomb::~Bomb() {
}

std::string const	&Bomb::getType() {
  return (this->_type);
}

bool	Bomb::initialize() {
  if (!_model.load("./assets/bomb.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
  }
  return (true);
}

void    Bomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) input;

  timer_bomb += clock.getElapsed();
  std::cout << "OBJECT N°: " << this->_id << std::endl;
  std::cout << "INFO CLOCK: " << clock.getElapsed() << std::endl;
  // if (!_hasExplosed)                                                         
  //   {                                                                        
  std::cout << "TIMER: " << timer_bomb << std::endl;
  std::cout << "CALCUL: " << (timer_bomb / 60) * 10 << std::endl;
  if ( ((timer_bomb / 60) * 10) > 0.1)
    {
      timer_bomb = 0;
      this->explose();
    }
  // }                                                                        
}

void	Bomb::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
   _model.draw(shader, getTransformation(), GL_QUADS);
}

bool    Bomb::explose()
{
  int   currentX = round((getPosition().x * 2) / 60);
  int   currentY = round((getPosition().z * 2) / 60);
  AObject* expl1 = new Explosion(glm::vec3(30 * currentX, 0, 30 * currentY),
                                 glm::vec3(0,0,0),
                                 glm::vec3(0.30, 0.30, 0.30),
                                 this->_listObjects);
  AObject* expl2 = new Explosion(glm::vec3(30 * currentX, 0,
                                           30 * (currentY - 1)),
                                 glm::vec3(0,0,0),
                                 glm::vec3(0.30, 0.30, 0.30),
                                 this->_listObjects);
  AObject* expl3 = new Explosion(glm::vec3(30 * currentX, 0,
                                           30 * (currentY + 1)),
                                 glm::vec3(0,0,0),
                                 glm::vec3(0.30, 0.30, 0.30),
                                 this->_listObjects);
  AObject* expl4 = new Explosion(glm::vec3(30 * (currentX - 1), 0,
                                           30 * currentY),
                                 glm::vec3(0,0,0),
                                 glm::vec3(0.30, 0.30, 0.30),
                                 this->_listObjects);
  AObject* expl5 = new Explosion(glm::vec3(30 * (currentX + 1), 0,
                                           30 * currentY),
                                 glm::vec3(0,0,0),
                                 glm::vec3(0.30, 0.30, 0.30),
                                 this->_listObjects);

  std::cout << "Position Explosion: ";
  std::cout << "X: " << round((getPosition().x * 2) / 60)  << " Y: " <<
    round((getPosition().z * 2) / 60) << std::endl;

  if (expl1->initialize() == false || expl2->initialize() == false ||
      expl3->initialize() == false || expl4->initialize() == false ||
      expl5->initialize() == false)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "explosion init");
  this->_listObjects.push_back(expl1);
  this->_listObjects.push_back(expl2);
  this->_listObjects.push_back(expl3);
  this->_listObjects.push_back(expl4);
  this->_listObjects.push_back(expl5);

  this->breakItems();

  this->_hasExplosed = true;
  this->_hasToBeRemove = true;

  return (true);
}

void		Bomb::breakItems()
{
  int		currentX = round((getPosition().x * 2) / 60);
  int		currentY = round((getPosition().z * 2) / 60);
  Coordinates	pos(currentX, currentY);  
  
  this->checkAround(pos);
  
  pos.setX(currentX);
  pos.setY(currentY - 1);
  this->checkAround(pos);

  pos.setX(currentX);
  pos.setY(currentY + 1);
  this->checkAround(pos);

  pos.setX(currentX - 1);
  pos.setY(currentY);
  this->checkAround(pos);

  pos.setX(currentX + 1);
  pos.setY(currentY);
  this->checkAround(pos);

  this->_touchPlayer = false;
}

void		Bomb::checkAround(Coordinates pos)
{
  typedef std::multimap<Coordinates, AObject*>::iterator mapIt;
  std::pair<mapIt, mapIt> resultat = this->_map.equal_range(pos);

  resultat = this->_map.equal_range(pos);
  for (mapIt it = resultat.first; it != resultat.second; ++it)
    {
      if (it->second->isBreakable())
	{
	  it->second->setExplosed();
	  this->_map.erase(it);
	  break;
	}
    }
  resultat = this->_map.equal_range(pos);
  for (mapIt it = resultat.first; it != resultat.second; ++it)
    {
      if (it->second->getType() == "Character" && !this->_touchPlayer)
        {
	  std::cout << "POS PLAYER (" << pos.getX() << "," << pos.getY() <<
            ")" << std::endl;
          this->_touchPlayer = it->second->receiveDamage();
        }
    }
}
