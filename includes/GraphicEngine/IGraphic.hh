//
// IGraphic.hh for IGraphic in /home/marghe_r/rendu/cpp_bomberman
// 
// Made by romain margheriti
// Login   <marghe_r@epitech.net>
// 
// Started on  Fri Jun 12 16:48:28 2015 romain margheriti
// Last update Thu Jun 18 19:17:53 2015 SOIDIKI Djamil
// Last update Wed Jun 17 23:57:08 2015 romain margheriti
//

#ifndef __IGRAPHIC_HH__
#define	__IGRAPHIC_HH__

#include	<vector>
#include	<Game.hh>
#include	<SdlContext.hh>
#include	"../common/AObject.hh"
#include	"Camera.hh"

class IGraphic : public gdl::Game {
	gdl::SdlContext _sdlContext;
	gdl::Input _input;
	gdl::Clock _clock;
	std::vector<AObject*> _objects;
	Camera *_camera;

public:
	IGraphic();
	~IGraphic();

	bool initialize();
	bool update();
	void draw();
};

#endif
