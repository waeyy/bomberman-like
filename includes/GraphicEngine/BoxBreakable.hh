//
// BoxBreakable.hh for  in /home/soidik_d/Downloads/old-june/Bomberman-romain/includes/GraphicEngine
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Jun 22 16:25:56 2015 SOIDIKI Djamil
// Last update Mon Jun 22 16:26:38 2015 SOIDIKI Djamil
//

#ifndef		_BOXBREAKABLE_HH_
# define	_BOXBREAKABLE_HH_

#include	<Model.hh>
#include	"../common/AObject.hh"

class		BoxBreakable : public AObject {
private :
  gdl::Model	_model;

public :
  BoxBreakable(glm::vec3, glm::vec3, glm::vec3);
  virtual ~BoxBreakable();

  virtual bool initialize();
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual std::string const &getType();
};

#endif
