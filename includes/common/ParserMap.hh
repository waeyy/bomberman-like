//
// ParserMap.hh for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/includes/common
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sat Jun 20 08:32:30 2015 SOIDIKI Djamil
// Last update Mon Jun 22 18:59:09 2015 SOIDIKI Djamil
//

#ifndef		_PARSERMAP_HH_
# define	_PARSERMAP_HH_

#include	<map>
#include	"Parser.hh"
#include	"../GameEngine/Coordinates.hh"
#include	"AObject.hh"

#define		START_DELIMIT_LEVEL		"number=\""
#define		START_DELIMIT_DIFFICULTY	"difficulty=\""
#define		START_DELIMIT_XSIZE		"x=\""
#define		START_DELIMIT_YSIZE		"y=\""
#define		START_DELIMIT_POS		"pos=\""
#define		START_DELIMIT_TYPE		"type=\""
#define		STOP_DELIMIT			"\" "
#define		COEFF_SCALE			0.30

class		ParserMap : public Parser {

private:
  int					_level;
  std::string				_difficulty;
  int					_sizeWidth;
  int					_sizeHeight;
  //std::map<Coordinates, AObject*>&	_maps;
  
  std::multimap<Coordinates, AObject*>& _map;

  std::vector<AObject*>&		_listObjects;

  int					_currentX;
  int					_currentY;

public:
  ParserMap(std::string, 
	    std::multimap<Coordinates, AObject*>&, 
	    std::vector<AObject*>&);
  virtual ~ParserMap();

  virtual void	parse();
  void		readLineContent(std::string, unsigned int);
  void		setLevel(std::string);
  void		setDifficulty(std::string);
  void		setSize(std::string);
  void		updateMap(std::string);
  void		updateCurrentY(std::string);
  std::string	getSubstr(std::string, std::string, bool);
  void		addObjectToMap(std::string);
  void		addGroundToMap();
  void		addWallToMap();
  void		addBoxToMap();
  void		addBoxBreakableToMap();
  
  int					getLevel() const;
  std::string				getDifficulty() const;
  int					getSizeWidth() const;
  int					getSizeHeight() const;
  //  std::map<Coordinates, AObject*>	getMap() const;
};

#endif		/* _PARSER_HH_ */
