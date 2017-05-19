//
// IGraphic.cpp for bomberman in /home/marghe_r/rendu/cpp_bomberman/lib
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Tue Jun  9 17:29:08 2015 romain margheriti
// Last update Sat Jun 20 18:33:59 2015 romain margheriti
// Last update Thu Jun 18 10:34:06 2015 romain margheriti
//

#include <unistd.h>
#include "../../includes/GraphicEngine/IGraphic.hh"
#include "../../includes/GraphicEngine/Character.hh"
#include "../../includes/GraphicEngine/Ground.hh"
#include "../../includes/GraphicEngine/Camera.hh"
#include "../../includes/common/ParseurXml.hh"
#include "../../includes/GraphicEngine/Box.hh"
#include "../../includes/GraphicEngine/Bomb.hh"

IGraphic::IGraphic() {
}

IGraphic::~IGraphic() {
  /*for (size_t i = 0; i < _objects.size(); ++i)
    {
      std::cout << "taille " << _objects.size() << std::endl;
      delete _objects[i];
      }*/
}

bool		IGraphic::initialize()
{
  ParseurXml	parseur;
  AObject	*perso = new Character(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.04, 0.04, 0.04));
  AObject	*box= new Box(glm::vec3(-10, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.04, 0.04, 0.04));
  int		i = -1;
  int		x = 0;
  int		y = 0;

  _camera = new Camera(*perso);

  if (!_sdlContext.start(1280, 720, "Bomberman", SDL_INIT_VIDEO | SDL_INIT_JOYSTICK))
    return (false);
    if (perso->initialize() == false)
    return (false);
  _objects.push_back(perso);

  if ((parseur.init_set_map("map/level1.xml")) == 1)
    return (false);
  while (++i < parseur.getSize())
    {
      if (x == parseur.getSizeY())
	{
	  x = 0;
	  y += 1;
	}
      if (parseur.check_status_ground(i) == 1)
	{
	  AObject *ground = new Ground(glm::vec3((x * 30), 0, (y * 30)), glm::vec3(0, 0, 0), glm::vec3(0.04, 0.04, 0.04));
	  if (ground->initialize() == false)
	    return (false);
	  _objects.push_back(ground);
	}
      x += 1;
    }

  std::cout << "Nombre de controller = " << SDL_NumJoysticks() << std::endl;
  
  if (perso->initialize() == false)
    return (false);
  if (box->initialize() == false)
    return (false);
  perso->setObjects(&_objects);
  _objects.push_back(perso);
  _objects.push_back(box);
  glEnable(GL_DEPTH_TEST);
  
  if (!_camera->initialize())
    return (false);
  return true;
}

bool	IGraphic::update() {
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;

  _sdlContext.updateClock(_clock);
  _sdlContext.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i) {
    _objects[i]->update(_clock, _input);
  }
  _camera->calculateCameraPosition();
  return true;  
}

void	IGraphic::draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _camera->getShader().bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_camera->getShader(), _clock);
  _camera->replaceCameraPosition();
  _sdlContext.flush();
  usleep((1000/60) - _clock.getElapsed());
}
