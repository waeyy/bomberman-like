//
// Explosion.hh for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/includes/GraphicEngine
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sat Jun 20 18:24:44 2015 SOIDIKI Djamil
// Last update Tue Jun 23 13:58:29 2015 SOIDIKI Djamil
//

#ifndef		_EXPLOSION_HH_
# define	_EXPLOSION_HH_

#include	<Model.hh>
#include	"../common/AObject.hh"

extern float	timer_explosion;

class		Explosion : public AObject {
private :
  gdl::Model		_model;
  std::vector<AObject*>&_listObjects;

public :
  Explosion(glm::vec3, glm::vec3, glm::vec3);
  Explosion(glm::vec3, glm::vec3, glm::vec3, std::vector<AObject*>&);
  virtual ~Explosion();

  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual std::string const &getType();
  void		removeExplosion();
};

#endif
