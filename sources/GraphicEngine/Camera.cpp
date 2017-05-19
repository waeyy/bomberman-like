//
// Camera.cpp for Camera in /home/marghe_r/rendu/cpp_bomberman/sources
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Thu Jun 18 20:42:26 2015 romain margheriti
// Last update Tue Jun 23 03:53:36 2015 romain margheriti
//

#include	<glm/gtc/matrix_transform.hpp>
#include	"../../includes/GraphicEngine/Camera.hh"
#include	<iostream>

Camera::Camera(glm::vec3 position, float fov) :
  _position(position), _fov(fov)
{
  _cameraUp = glm::vec3(0, 1, 0);
  projection = glm::perspective(_fov, 1280.0f / 720.0f, 0.1f, 1000.0f);
}

Camera::~Camera() {

}

bool	Camera::initialize() {
  return (true);
}

void	Camera::update() {
}

gdl::BasicShader	&Camera::getShader() {
  return (_shader);
}


/*************PANORAMIC VIEW*********************/

Panoramic::Panoramic():
  Camera(glm::vec3(1, 300, 300), 120.0f)
{
}

Panoramic::~Panoramic() {
}

bool	Panoramic::initialize() {
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  _shader.bind();
  _shader.setUniform("projection", projection);
  _target = glm::vec3(0, 0, 0);
  return (true);
}

void	Panoramic::update() {
}

void	Panoramic::replace() {
  transformation = glm::lookAt(_position, _target, _cameraUp);
  _shader.bind();
  _shader.setUniform("view", transformation);
}
/***************THIRD PERSONNE**********************/

ThirdPersonne::ThirdPersonne(AObject &target) : 
  Camera(target.getPosition(), 60.0f), _model(target)
{
  _angleAroundPlayer = 180;

  _verticalDistance = 50;
  _horizontalDistance = 86.603;
}

ThirdPersonne::~ThirdPersonne() {
}

bool	ThirdPersonne::initialize() {
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  _shader.bind();
  _shader.setUniform("projection", projection);
  return (true);
}

void	ThirdPersonne::update() {
  float theta = _model.getRotation().y + _angleAroundPlayer;
  float offsetX = _horizontalDistance * glm::sin(glm::radians(theta));
  float offsetZ = _horizontalDistance * glm::cos(glm::radians(theta));
  
  _position.x = _model.getPosition().x + offsetX;
  _position.z = _model.getPosition().z + offsetZ;
  _position.y = _model.getPosition().y + _verticalDistance;
}

void	ThirdPersonne::replace() {
  transformation = glm::lookAt(_position, _model.getPosition(), _cameraUp);
  _shader.setUniform("view", transformation);
}


/***************UPPER VIEW**************************/

Upper::Upper():
  Camera(glm::vec3(200, 300, 50), 100.0f)
{
}

Upper::~Upper() {
}

bool	Upper::initialize() {
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  _target = glm::vec3(200, 0, 10);
  _shader.bind();
  _shader.setUniform("projection", projection);
  return (true);
}

void	Upper::update() {
}

void	Upper::replace() {
  transformation = glm::lookAt(_position, _target, _cameraUp);
  _shader.bind();
  _shader.setUniform("view", transformation);
}

/*****************firstPersonne*****************/

FirstPersonne::FirstPersonne(AObject &target) : 
  Camera(target.getPosition(), 60.0f), _model(target)
{
  _angleAroundPlayer = 180;

  _verticalDistance = 40;
  _horizontalDistance = 0;
}

FirstPersonne::~FirstPersonne() {
}

bool	FirstPersonne::initialize() {
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  _shader.bind();
  _shader.setUniform("projection", projection);
  return (true);
}

void	FirstPersonne::update() {
  float theta = _model.getRotation().y + _angleAroundPlayer;
  float offsetX = _horizontalDistance * glm::sin(glm::radians(theta));
  float offsetZ = _horizontalDistance * glm::cos(glm::radians(theta));
  
  _position.x = _model.getPosition().x + offsetX;
  _position.z = _model.getPosition().z + offsetZ;
  _position.y = _model.getPosition().y + _verticalDistance;
}

void	FirstPersonne::replace() {
  transformation = glm::lookAt(_position, _model.getPosition()+ glm::vec3(0, 50, 1), _cameraUp);
  _shader.setUniform("view", transformation);
}
