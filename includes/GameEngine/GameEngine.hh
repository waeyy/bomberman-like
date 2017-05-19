//
// GameEngine.hh for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/includes
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Jun 16 21:54:47 2015 SOIDIKI Djamil
// Last update Tue Jun 23 14:58:43 2015 SOIDIKI Djamil
//

#ifndef		_GAMEENGINE_H_
# define	_GAMEENGINE_H_

#include	<vector>
#include	<map>
#include	<Game.hh>
#include	<SdlContext.hh>
#include	"../common/AObject.hh"
#include	"../GraphicEngine/Camera.hh"
#include	"Coordinates.hh"
#include	"Options.hh"

#define		WIDTH_SCREEN	1280
#define		HEIGHT_SCREEN	720
#define		TITLE_SCREEN	"Bomberman"

class		GameEngine : public gdl::Game {

private:
  gdl::SdlContext			_sdlContext;
  gdl::Input				_input;
  gdl::Clock				_clock;
  std::vector<AObject*>			_objects;
  Camera*				_camera;
  std::multimap<Coordinates, AObject*>	_map;
  Options*				_options;

public:
  GameEngine(Options* opt);
  ~GameEngine();

  bool			initialize();
  bool			update();
  void			draw();
  void			init_floor();
  void			testView(gdl::Input &);
};

#endif		/* _GAMEENGINE_H_ */
