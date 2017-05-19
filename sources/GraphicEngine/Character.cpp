//
// Character.cpp for character in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:49:44 2015 romain margheriti
// Last update Tue Jun 23 13:53:32 2015 SOIDIKI Djamil
//


/*
  vie 100 arrivé à 0 game over
  monstre
 */

#include "../../includes/common/Exception.hh"
#include "../../includes/GraphicEngine/Character.hh"
#include "../../includes/GraphicEngine/Bomb.hh"
#include "../../includes/common/AObject.hh"
#include "../../includes/GameEngine/Coordinates.hh"
#include <SDL_joystick.h>
#include <iostream>

Character::Character(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale,
		     std::vector<AObject*>& objects, 
		     std::multimap<Coordinates, AObject*> &map,
		     int *key, int id) :
  AObject(position, rotation, scale, *new std::string("Character")), 
  RUNSPEED(100), TURNSPEED(160), 
  _listObjects(objects), _map(map), _id(id)
{
  this->_controller = NULL;
  this->_currentSpeed = 0;
  this->_currentTurn = 0;
  this->_isBreakable = false;

  this->_health = 100;
  this->_score = 0;
  this->_isAlive = true;
  _keyTab = key;
}

Character::~Character() {
}

bool	Character::initialize() {
  if (!_model.load("./assets/marvin.fbx")) {
    std::cout << "Error during asset loading" << std::endl;
    return (false);
  }   
  controllerBindage();
  this->_model.setCurrentAnim(0, true);
  this->_model.createSubAnim(0, "Pause", 85, 123);
  this->_model.createSubAnim(0, "Run", 40, 55);
  this->_model.setCurrentSubAnim("Pause", true);
  return (true);
}

bool	Character::controllerBindage() {
  SDL_JoystickEventState(SDL_ENABLE);  
  this->_controller = SDL_JoystickOpen(_id);
  if (_controller == NULL)
    std::cout << "contoller == null " << std::endl;
  else {
    std::cout << "Controller bindé " << _controller << std::endl;
    std::cout << "Button = " << SDL_JoystickNumButtons(_controller) << std::endl;
    std::cout << "Axe = " << SDL_JoystickNumAxes(_controller) << std::endl;
    std::cout << "Hats = " << SDL_JoystickNumHats(_controller) << std::endl;
    std::cout << "Balls = " << SDL_JoystickNumBalls(_controller) << std::endl;
  }
  return (true);
}

std::string const &Character::getType() {
  return (_type);
}

bool	Character::checkMovement() {
  glm::vec3 tmp;
  
  float distance = 15;
  float dx = distance * glm::sin(glm::radians(_rotation.y));
  float dz = distance * glm::cos(glm::radians(_rotation.y));  
  tmp = _position + glm::vec3(dx, 0, dz);
  
  typedef std::multimap<Coordinates, AObject*>::iterator mapIt;
  
  Coordinates pos(round(((tmp.x * 2) / 60)), round(((tmp.z * 2) / 60)));
  std::pair<mapIt, mapIt> resultat = this->_map.equal_range(pos);

  for (mapIt it = resultat.first; it != resultat.second; ++it)
    {
      if (it->second->getType() == "Box" ||
	  it->second->getType() == "BoxBreakable" ||
	  it->second->getType() == "Wall" )
      	return (false);
    }
  return (true);
}

void	Character::move(gdl::Clock const &clock) {
  typedef std::multimap<Coordinates, AObject*>::iterator mapIt;
  std::pair<mapIt, mapIt> res = this->_map.equal_range(this->_coordinates);

  rotate(glm::vec3(0, 1, 0), 
	 _currentTurn * static_cast<float>(clock.getElapsed()));
  if (checkMovement()) {
    float distance = _currentSpeed *  static_cast<float>(clock.getElapsed());
    float dx = distance * glm::sin(glm::radians(_rotation.y));
    float dz = distance * glm::cos(glm::radians(_rotation.y));
    translate(glm::vec3(dx, 0, dz));

    glm::vec3 tmp;
    tmp = this->_position + glm::vec3(dx, 0, dz);
    int	newX = round((tmp.x * 2) / 60);
    int	newY = round((tmp.z * 2) / 60);
    
    for (mapIt it = res.first; it != res.second; ++it)
      {
	if (it->second->getType() == "Character")
	  {
	    this->_map.erase(it);
	    break;
	  }
      }
    this->_map.insert(std::make_pair(Coordinates(newX, newY), this));
  }
}

void	Character::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
  _model.draw(shader, getTransformation(), clock.getElapsed());
}

void	Character::controllerUpadte() {
  SDL_Event event;
 
  while(SDL_PollEvent(&event))
    {  
      switch(event.type)
        {  
	  
	case SDL_JOYAXISMOTION:  /* Handle Joystick Motion */
	  if ( ( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 ) ) 
	    {
	      if( event.jaxis.axis == 0) 
		{
		  std::cout << "Left-right movement code goes here" << std::endl;
		}
	      
	      if( event.jaxis.axis == 1) 
		{
		  std::cout << "Up-Down movement code goes here" << std::endl;
		}
	    }
	  break;
	}
    }
}

void Character::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_isAlive)
    this->_score += 1;
  _coordinates = Coordinates(round(((_position.x * 2) / 60)), round(((_position.z * 2) / 60)));
  if (_controller == NULL) {
    (void)clock;
    if (input.getKey(_keyTab[1]))
      {
	_currentSpeed = -RUNSPEED;
	_canpause = false;
	if (_canrun == false)
	  {
	    _model.setCurrentSubAnim("Run", true);
	    _canrun = true;
	  }
      }
    else if (input.getKey(_keyTab[0]))
      {
	_currentSpeed = RUNSPEED;
      _canpause = false;
      if (_canrun == false)
        {
          _model.setCurrentSubAnim("Run", true);
          _canrun = true;
        }
      }
    else
      {
	_canrun = false;
	_currentSpeed = 0;
	if (_canpause == false)
	  {
	    _model.setCurrentSubAnim("Pause", false);
	    _canpause = true;
	  }
      }
    if (input.getKey(_keyTab[2]))
      _currentTurn = TURNSPEED;
    else if (input.getKey(_keyTab[3]))
      _currentTurn = -TURNSPEED;
    else
      _currentTurn = 0;
    if (input.getKey(_keyTab[4])) {
      AObject *bomb = new Bomb(getPosition(), 
			       glm::vec3(0,0,0), 
			       glm::vec3(0.15, 0.15, 0.15),
			       this->_listObjects,
			       this->_map);
      
      if (bomb->initialize() == false)
	throw Exception(NO_ERRNO, __LINE__, __FILE__, "bomb init");
      this->_listObjects.push_back(bomb);
      while (input.getKey(SDLK_SPACE))
	input.removeKeyInput(_keyTab[4]);
    } else 
      controllerUpadte();
    move(clock);
  }
}

bool            Character::receiveDamage()
{
  std::cout << "Player à subit des dégats !" << std::endl;
  if (this->_health > 0)
    this->_health -= 50;
  else
    {
      std::cout << "Player est mort ! Il a un score de: " << this->_score <<
        std::endl;
      this->_isAlive = false;
    }
  return (true);
}
