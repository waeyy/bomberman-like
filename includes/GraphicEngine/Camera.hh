//
// camera.hh for camera in /home/marghe_r/rendu/cpp_bomberman/includes
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Thu Jun 18 20:34:24 2015 romain margheriti
// Last update Sun Jun 21 02:24:22 2015 romain margheriti
//


#ifndef		__CAMERA_HH__
# define	__CAMERA_HH__

#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<BasicShader.hh>
#include	"../../includes/common/AObject.hh"

class		Camera {
public :
  Camera(glm::vec3, float);
  virtual ~Camera();
  virtual bool initialize();
  virtual void update();
  virtual void replace() = 0;
          gdl::BasicShader &getShader();
protected:
  glm::vec3	_position;
  glm::vec3	_target;
  glm::vec3	_cameraUp;
  float		_fov;

  glm::mat4	projection;
  glm::mat4	transformation;

  gdl::BasicShader	_shader;

};

class	ThirdPersonne : public Camera {
private :
  AObject	&_model;
  float		_distanceFromPlayer;
  float		_angleAroundPlayer;

  float		_verticalDistance;
  float		_horizontalDistance;

public:
  ThirdPersonne(AObject &);
  ~ThirdPersonne();
  virtual bool initialize();
  virtual void update();
  virtual void replace();
};

class	Panoramic : public Camera {
public:
  Panoramic();
  ~Panoramic();
  virtual bool initialize();
  virtual void update();
  virtual void replace();
};

class	Upper : public Camera {
public:
  Upper();
  ~Upper();
  virtual bool initialize();
  virtual void update();
  virtual void replace();
};

class	FirstPersonne : public Camera {
  private :
  AObject	&_model;
  float		_angleAroundPlayer;

  float		_verticalDistance;
  float		_horizontalDistance;
public:
  FirstPersonne(AObject&);
  ~FirstPersonne();
  virtual bool initialize();
  virtual void update();
  virtual void replace();
};

#endif
