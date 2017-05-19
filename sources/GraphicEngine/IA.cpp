//
// IA.cpp<sources> for bomb in /home/pallat_o/rendu/Tek2/cpp_bomberman/sources/GameEngine
// 
// Made by Olivier Pallatier
// Login   <pallat_o@epitech.net>
// 
// Started on  Mon Jun 22 01:25:27 2015 Olivier Pallatier
// Last update Tue Jun 23 15:43:21 2015 SOIDIKI Djamil
//

#include		<iostream>

#include		"../../includes/common/AObject.hh"
#include		"../../includes/common/Exception.hh"
#include		"../../includes/GraphicEngine/Character.hh"
#include		"../../includes/GraphicEngine/Bomb.hh"
#include		"../../includes/GameEngine/Coordinates.hh"
#include		"../../includes/GraphicEngine/IA.hh"

IA::IA(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale,
       std::vector<AObject*>& objects, std::multimap<Coordinates, AObject*> &map) :
  AObject(position, rotation, scale, *new std::string("IA")), RUNSPEED(40), TURNSPEED(160),
  _listObjects(objects), _map(map)
{
  _controller = NULL;
  _currentSpeed = 0;
  _currentTurn = 0;
}

IA::~IA()
{
}

bool			error_return(const std::string str)
{
  std::cout << str << std::endl;
  return false;
}

std::string const &	IA::getType()
{
  return _type;
}

void			IA::draw(gdl::AShader &shader, gdl::Clock const&clock)
{
  (void)clock;
  _model.draw(shader, getTransformation(), GL_QUADS);
}

void			IA::putBomb()
{
  AObject *bomb = new Bomb(getPosition(),
			   glm::vec3(0, 0, 0),
			   glm::vec3(0.2, 0.2, 0.2),
			   this->_listObjects,
			   this->_map);
  if (bomb->initialize() == false)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "bomb init");
  this->_listObjects.push_back(bomb); 
}

bool			IA::checkMovement(gdl::Clock const &clock)
{
  glm::vec3		tmp;

  float			distance = 100 * static_cast<float>(clock.getElapsed());
  float			dx = distance * glm::sin(glm::radians(_rotation.y));
  float			dz = distance * glm::cos(glm::radians(_rotation.y));

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


  // if (_map[Coordinates(round(((tmp.x * 2) / 60)), round(((tmp.z * 2) / 60)))]->getType() != "Ground")
  //   return false;
  return true;
}

bool			IA::move(gdl::Clock const &clock)
{
  typedef std::multimap<Coordinates, AObject*>::iterator mapIt;
  std::pair<mapIt, mapIt> res = this->_map.equal_range(this->_coordinates);

  rotate(glm::vec3(0, 1, 0),
	 _currentTurn * static_cast<float>(clock.getElapsed()));
  if (checkMovement(clock))
    {
      float distance = _currentSpeed * static_cast<float>(clock.getElapsed());
      float dx = distance * glm::sin(glm::radians(_rotation.y));
      float dz = distance * glm::cos(glm::radians(_rotation.y));
      translate(glm::vec3(dx, 0, dz));
      
      glm::vec3 tmp;
      tmp = this->_position + glm::vec3(dx, 0, dz);
      int newX = round((tmp.x * 2) / 60);
      int newY = round((tmp.z * 2) / 60);

      for (mapIt it = res.first; it != res.second; ++it)
	{
	  if (it->second->getType() == "Character")
	    {
	      this->_map.erase(it);
	      break;
	    }
	}
      this->_map.insert(std::make_pair(Coordinates(newX, newY), this));
      
      //_map[Coordinates(dx, dz)] = this;
      return true;
    }
  return false;
}

void			IA::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)input;
  int			bombProbability;
  
  _currentSpeed = RUNSPEED * 1.5;
  _coordinates = Coordinates(round(((_position.x * 2) / 60)), round(((_position.z * 2) / 60)));
  bombProbability = rand() % 600;
  if (bombProbability <= 2 && bombProbability >= 0)
    putBomb();
  while (move(clock) == false)
    {
      _currentSpeed = 0;
      _currentTurn = TURNSPEED * 10;
    }
  _currentTurn = 0;
  _currentSpeed = RUNSPEED * 1.5;
}

bool			IA::initialize()
{
  if (!_model.load("./assets/marvin.fbx"))
    return error_return("IA -> Error during 'Marvin' asset loading");
  return true;
}
