//
// Groupex.hh for ground in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Mon Jun 15 15:26:07 2015 romain margheriti
// Last update Fri Jun 19 19:42:34 2015 romain margheriti
//

#ifndef		__GROUND_HH__
# define	__GROUND_HH__

#include	<Model.hh>
#include	"../common/AObject.hh"

class		Ground : public AObject {
private :
  gdl::Model	_model;
  float		_speed;

public :
  Ground(glm::vec3, glm::vec3, glm::vec3);
  virtual ~Ground();

  virtual bool initialize();
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual std::string const &getType();
};

#endif
