//
// GameEngine.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Jun 16 22:00:49 2015 SOIDIKI Djamil
// Last update Tue Jun 23 15:55:00 2015 SOIDIKI Djamil
//

#include	"../../includes/common/Exception.hh"
#include	"../../includes/GameEngine/GameEngine.hh"
#include	"../../includes/GameEngine/Coordinates.hh"
#include	"../../includes/GraphicEngine/Character.hh"
#include	"../../includes/GraphicEngine/Ground.hh"
#include	"../../includes/GraphicEngine/Camera.hh"
#include	"../../includes/GraphicEngine/Box.hh"
#include	"../../includes/GraphicEngine/Bomb.hh"
#include	"../../includes/GraphicEngine/IA.hh"
#include	<unistd.h>

#include	"../../includes/common/ParserMap.hh"

GameEngine::GameEngine(Options* opt) : _options(opt)
{
}

GameEngine::~GameEngine()
{
}

bool		GameEngine::initialize()
{
  int	nbrPlayer = this->_options->getNbPlayers();
  int	*stdKey = new int[5];
  
  stdKey[0] = SDLK_UP;
  stdKey[1] = SDLK_DOWN;
  stdKey[2] = SDLK_LEFT;
  stdKey[3] = SDLK_RIGHT;
  stdKey[4] = SDLK_SPACE;

  if (!this->_sdlContext.start(WIDTH_SCREEN, HEIGHT_SCREEN, TITLE_SCREEN, 
			       SDL_INIT_VIDEO | SDL_INIT_JOYSTICK))
    return (false);
  glEnable(GL_DEPTH_TEST);
  
  if (nbrPlayer == 1) {
    AObject*	perso = new Character(glm::vec3(30 * 1, 0, 30 * 1), 
				      glm::vec3(0, 0, 0), 
				      glm::vec3(0.04, 0.04, 0.04),
				      this->_objects, this->_map, stdKey, 0);

    _camera = new ThirdPersonne(*perso);
    if (!this->_camera->initialize())
      return (false);
    
    if (perso->initialize() == false)
      return (false);

    this->_objects.push_back(perso);
    this->_map.insert(std::make_pair(Coordinates(1, 1), perso));  
  } else {
    int	*key2 = new int[5];
    
    key2[0] = SDLK_z;
    key2[1] = SDLK_s;
    key2[2] = SDLK_q;
    key2[3] = SDLK_d;
    key2[4] = SDLK_w;

    AObject*	perso = new Character(glm::vec3(30 * 1, 0, 30 * 1), 
				      glm::vec3(0, 0, 0), 
				      glm::vec3(0.04, 0.04, 0.04),
				      this->_objects, this->_map, stdKey, 0);
    
    AObject*	perso2 = new Character(glm::vec3(30 * 2, 0, 30 * 1), 
				      glm::vec3(0, 0, 0), 
				      glm::vec3(0.04, 0.04, 0.04),
				       this->_objects, this->_map, key2, 1);

    _camera = new Upper();
    if (!this->_camera->initialize())
      return (false);
    

    if (perso->initialize() == false)
      return (false);
    if (perso2->initialize() == false)
      return (false);

    this->_objects.push_back(perso);
    this->_objects.push_back(perso2);
    this->_map.insert(std::make_pair(Coordinates(1, 1), perso));
    this->_map.insert(std::make_pair(Coordinates(2, 1), perso2));  
  }

  // int	i;
  
  // i = -1;
  // while (++i < (int) this->_options->getNbIa())
  //   {
  //     AObject*      ia = new IA(glm::vec3(30 * (i + 1), 0, 30 * (i + 1)),
  // 				glm::vec3(0, 0, 0),
  // 				glm::vec3(0.04, 0.04, 0.04),
  // 				this->_objects, this->_map);
  //     if (ia->initialize() == false)
  // 	return (false);
  //     this->_objects.push_back(ia);
  //     this->_map.insert(std::make_pair(Coordinates((i+1), (i+1)), ia));
  //   }
  this->init_floor();
  return true;
}

void		GameEngine::init_floor()
{
  ParserMap	parserMap("map/" + this->_options->getMap(), 
			  this->_map, this->_objects);
  parserMap.parse();
}

void	GameEngine::testView(gdl::Input &input) {
  if (input.getKey(SDLK_F1)) {
    Camera *camera = new Panoramic();
    camera->initialize();
    delete (_camera);
    _camera = camera;
  } else if (input.getKey(SDLK_F2)) {
    Camera *camera = new ThirdPersonne(*_objects[0]);
    camera->initialize();
    delete (_camera);
    _camera = camera;
  } else if (input.getKey(SDLK_F3)) {
    Camera *camera = new Upper();
    camera->initialize();
    delete (_camera);
    _camera = camera;
  } else if (input.getKey(SDLK_F4)) {
    Camera *camera = new FirstPersonne(*_objects[0]);
    camera->initialize();
    delete (_camera);
    _camera = camera;
  }
}

bool		GameEngine::update()
{  
  if (this->_input.getKey(SDLK_ESCAPE) || this->_input.getInput(SDL_QUIT))
    return false;
  this->_sdlContext.updateClock(this->_clock);
  this->_sdlContext.updateInputs(this->_input);
  testView(this->_input);
  for (size_t i = 0; i < this->_objects.size(); ++i) {
    if (this->_objects[i]->getHasToBeRemove() || 
	this->_objects[i]->isExplosed())
      this->_objects.erase(this->_objects.begin() + i);
    else
      this->_objects[i]->update(this->_clock, this->_input);
  }
  this->_camera->update();
  return true;  
}

void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->_camera->getShader().bind();
  for (size_t i = 0; i < this->_objects.size(); ++i)
    this->_objects[i]->draw(this->_camera->getShader(), this->_clock);
  this->_camera->replace();
  this->_sdlContext.flush();
  usleep((1000/60) - this->_clock.getElapsed());
}
