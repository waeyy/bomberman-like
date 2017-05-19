//
// Character.cpp for character in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:17:40 2015 romain margheriti
// Last update Sat Jun 20 18:10:21 2015 romain margheriti
//

#ifndef		__WALL_HH__
# define	__WALL_HH__

#include	<Model.hh>
#include	"../common/AObject.hh"

class		Wall : public AObject {
private :
  gdl::Model	_model;

public :
  Wall(glm::vec3, glm::vec3, glm::vec3);
  virtual ~Wall();

  virtual bool initialize();
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual std::string const	&getType();
};

#endif
