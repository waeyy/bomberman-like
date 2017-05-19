//
// Bomb.hh for bomb in /home/marghe_r/rendu/cpp_bomberman
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Thu Jun 18 02:33:26 2015 romain margheriti
// Last update Tue Jun 23 12:33:22 2015 SOIDIKI Djamil
//

#ifndef		__BOMB_HH__
# define	__BOMB_HH__

#include	<Model.hh>
#include	"../common/AObject.hh"
#include	"../GameEngine/Coordinates.hh"

extern float timer_bomb;

class		Bomb : public AObject {
private :
  gdl::Model			_model;
  std::vector<AObject*>&	_listObjects;
  bool                          _hasExplosed;
  bool                          _resetTimer;
  std::multimap<Coordinates, AObject*>& _map;
  bool				_touchPlayer;

public :
  Bomb(glm::vec3, glm::vec3, glm::vec3);
  Bomb(glm::vec3, glm::vec3, glm::vec3, std::vector<AObject*>&,
       std::multimap<Coordinates, AObject*>&);
  virtual ~Bomb();

  virtual bool	initialize();
  virtual void  update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual std::string const &getType();
  bool		explose();
  void		breakItems();
  void		checkAround(Coordinates);
};

#endif
