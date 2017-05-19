//
// AObject.hh for AOBJECT in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:29:28 2015 romain margheriti
// Last update Tue Jun 23 12:30:02 2015 SOIDIKI Djamil
//

#ifndef		__AOBJECT_HH__
# define	__AOBJECT_HH__

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <AShader.hh>
#include <map>
#include <vector>
#include <iostream>
#include "../GameEngine/Coordinates.hh"

class AObject
{
public:
  AObject(glm::vec3, glm::vec3, glm::vec3, std::string const &);
  AObject(glm::vec3, glm::vec3, glm::vec3, std::vector<AObject*>&, std::string const &);
  virtual ~AObject();

  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  virtual std::string const &getType() = 0;

  virtual bool controllerBindage(int number);
  virtual void setMap(std::map<Coordinates, AObject*> &);
  void translate(glm::vec3 const &v);
  void rotate(glm::vec3 const& axis, float angle);
  void scale(glm::vec3  const& scale);
  
  glm::mat4 getTransformation();

  virtual glm::vec3	getPosition();
  glm::vec3		getRotation();
  glm::vec3		getScale();
  Coordinates		&getCoordinates();
  void			setObjects(std::vector<AObject*> *);  
  std::vector<AObject*> *getObjects();
  bool                  getHasToBeRemove() const;
  bool			isBreakable() const;
  void			setExplosed();
  bool			isExplosed() const;
  virtual bool		receiveDamage();

protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
  std::vector<AObject*> *_objects;
  std::string const &_type;
  Coordinates _coordinates;
  unsigned int          _id;
  bool                  _hasToBeRemove;
  bool			_isBreakable;
  bool			_explosed;
};

#endif
