//
// IA.hh for bomb in /home/pallat_o/rendu/Tek2/cpp_bomberman/sources/GameEngine
// 
// Made by Olivier Pallatier
// Login   <pallat_o@epitech.net>
// 
// Started on  Mon Jun 22 01:26:11 2015 Olivier Pallatier
// Last update Tue Jun 23 15:38:39 2015 SOIDIKI Djamil
//

#ifndef			IA_HH_
# define		IA_HH_

# include		<map>
# include		<Model.hh>

# include		"../GameEngine/Options.hh"
# include		"../common/ParserMap.hh"
# include		"../GraphicEngine/Character.hh"
# include		"../GameEngine/Coordinates.hh"
# include		"../common/AObject.hh"

class			IA : public AObject
{
private:
  SDL_Joystick		*_controller;
  gdl::Model		_model;
  const float		RUNSPEED;
  float			_currentSpeed;
  const float		TURNSPEED;
  float			_currentTurn;
  
  std::vector<AObject*>&_listObjects;
  std::multimap<Coordinates, AObject*>&_map;

public:
  IA(glm::vec3, glm::vec3, glm::vec3,
     std::vector<AObject*>&, std::multimap<Coordinates, AObject*>&);
  virtual ~IA();

  virtual bool		initialize();
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock);
  
  virtual void		update(gdl::Clock const &clock, gdl::Input &input);
  virtual void		putBomb();
  
  virtual std::string const &getType();

  bool			checkMovement(gdl::Clock const &);
  bool			move(gdl::Clock const &);
  int			getLevel();
};

# endif			/* IA_HH_ */
