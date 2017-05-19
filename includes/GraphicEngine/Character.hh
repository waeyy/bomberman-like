//
// Character.cpp for character in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:17:40 2015 romain margheriti
// Last update Tue Jun 23 12:32:36 2015 SOIDIKI Djamil
//

#ifndef		__CHARACTER_HH__
# define	__CHARACTER_HH__

#include	<map>
#include	<Model.hh>
#include	"../GameEngine/Coordinates.hh"
#include	"../common/AObject.hh"

class		Character : public AObject {
private :
  SDL_Joystick	*_controller;

  gdl::Model	_model;
  const float	RUNSPEED;
  float		_currentSpeed;
  bool		_canpause;
  bool		_canrun;
  const float	TURNSPEED;
  float		_currentTurn;

  std::vector<AObject*>&	_listObjects;
  std::multimap<Coordinates, AObject*>	&_map;
 
  int		*_keyTab;
  int		_id;

  unsigned int  _health;
  unsigned int  _score;
  bool          _isAlive;

public :
  Character(glm::vec3, glm::vec3, glm::vec3, 
	    std::vector<AObject*>&, std::multimap<Coordinates, AObject*>&,
	    int*, int);

  virtual ~Character();

  virtual bool initialize();
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool controllerBindage();
  virtual std::string const &getType();

  virtual bool receiveDamage();

  void  controllerUpadte();
  void	move(gdl::Clock const &);
  bool	checkMovement();
};

#endif
