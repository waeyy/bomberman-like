//
// AObject.cpp for AObject in /home/marghe_r/rendu/cpp_bomberman/sources
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 18:33:03 2015 romain margheriti
// Last update Tue Jun 23 12:31:04 2015 SOIDIKI Djamil
//

#include "../../includes/common/AObject.hh"

AObject::AObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, std::string const &type) :
  _position(position), _rotation(rotation), _scale(scale), _type(type)
{
  this->_hasToBeRemove = false;
  this->_explosed = false;
  _coordinates = Coordinates(round((_position.x * 2) / 60), round((_position.z 
* 2) / 60));
}

AObject::~AObject()
{
}

std::string const	&AObject::getType() {
  std::cout << "AObject getType()" << std::endl;
  return (_type);
}

glm::vec3	AObject::getPosition() {
  return (_position);
}

glm::vec3	AObject::getRotation() {
  return (_rotation);
}

glm::vec3	AObject::getScale() {
  return (_scale);
}

std::vector<AObject*> *AObject::getObjects() {
  return (_objects);
}

Coordinates &AObject::getCoordinates() {
  return (_coordinates);
}

void		AObject::setObjects(std::vector<AObject*> *objects)
{
  _objects = objects;
}

void		AObject::setMap(std::map<Coordinates, AObject *> &map)
{  
  std::cout <<"coucou"<< std::endl;
  delete (&map);
}  

bool AObject::initialize()
{
  return (true);
}

void AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) clock;
  (void) input;
}

bool AObject::controllerBindage(int number)
{
  (void) number;
  return (true);
}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 AObject::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  return (transform);
}

bool            AObject::getHasToBeRemove() const
{
  return (this->_hasToBeRemove);
}

bool            AObject::isBreakable() const
{
  return (this->_isBreakable);
}

bool            AObject::isExplosed() const
{
  return (this->_explosed);
}

void		AObject::setExplosed()
{
  this->_explosed = true;
}

bool		AObject::receiveDamage()
{
  return (false);
}
