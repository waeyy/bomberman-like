//
// Character.cpp for character in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:17:40 2015 romain margheriti
// Last update Fri Jun 19 19:41:39 2015 romain margheriti
//

#ifndef		__BOX_HH__
# define	__BOX_HH__

#include	<Model.hh>
#include	"../common/AObject.hh"

class		Box : public AObject {
private :
  gdl::Model	_model;

public :
  Box(glm::vec3, glm::vec3, glm::vec3);
  virtual ~Box();

  virtual bool initialize();
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual std::string const &getType();
};

#endif
