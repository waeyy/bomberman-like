//
// ParserMap.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources/common
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sat Jun 20 08:37:19 2015 SOIDIKI Djamil
// Last update Tue Jun 23 11:07:11 2015 romain margheriti
//

#include	"../../includes/common/ParserMap.hh"
#include	"../../includes/GraphicEngine/Ground.hh"
#include	"../../includes/GraphicEngine/Box.hh"
#include	"../../includes/GraphicEngine/BoxBreakable.hh"
#include	"../../includes/GraphicEngine/Wall.hh"

ParserMap::ParserMap(std::string namefile, 
		     std::multimap<Coordinates, AObject*>& map, 
		     std::vector<AObject*>& objects) :
  Parser(namefile), _map(map), _listObjects(objects)
{
}

ParserMap::~ParserMap()
{
}

std::string	ParserMap::getSubstr(std::string lineContent, 
				     std::string startDelimiter, 
				     bool lastOccurence)
{
  std::size_t	start	= lineContent.find(startDelimiter);
  std::size_t	stop; 
  std::string	res;
  
  if (lastOccurence == true)
    {
      stop = lineContent.find_last_of(STOP_DELIMIT);
      res = lineContent.substr(start + strlen(startDelimiter.c_str()), 
			       stop - 1 - (start + 
					   strlen(startDelimiter.c_str())));
    }
  else
    {
      stop = lineContent.find(STOP_DELIMIT);
      res = lineContent.substr(start + strlen(startDelimiter.c_str()), 
			       stop - (start + 
				       strlen(startDelimiter.c_str())));
    }
  return (res);
}

void		ParserMap::setLevel(std::string lineContent)
{
  std::string	level;
  
  level = this->getSubstr(lineContent, START_DELIMIT_LEVEL, false);
  this->_level = atoi(level.c_str());
  //std::cout << this->_level << std::endl;
}

void		ParserMap::setDifficulty(std::string lineContent)
{
  std::size_t	start	= lineContent.find(START_DELIMIT_DIFFICULTY);
  std::size_t	stop	= lineContent.find_last_of(STOP_DELIMIT);
  std::string	diff;
  
  diff = lineContent.substr(start + strlen(START_DELIMIT_DIFFICULTY), 
			    stop - (start + 
				    strlen(START_DELIMIT_DIFFICULTY)) - 1);
  this->_difficulty = diff;
  //std::cout << this->_difficulty << std::endl;
}

void		ParserMap::setSize(std::string lineContent)
{
  std::string	xsize;
  std::string	ysize; 

  xsize = this->getSubstr(lineContent, START_DELIMIT_XSIZE, false);  
  this->_sizeWidth = atoi(xsize.c_str());
  //std::cout << "X = " << this->_sizeWidth << std::endl;
  ysize = this->getSubstr(lineContent, START_DELIMIT_YSIZE, true);
  this->_sizeHeight = atoi(ysize.c_str());
  //std::cout << "Y = " << this->_sizeHeight << std::endl;
}

void		ParserMap::updateCurrentY(std::string lineContent)
{
  std::string	currentY;
  
  currentY = this->getSubstr(lineContent, START_DELIMIT_POS, false);
  this->_currentY = atoi(currentY.c_str());
  //std::cout << this->_currentY << std::endl;
}

void		ParserMap::addObjectToMap(std::string lineContent)
{
  std::string	posX;
  std::string	typeObject;

  posX = this->getSubstr(lineContent, START_DELIMIT_POS, false);
  this->_currentX = atoi(posX.c_str());
  typeObject = this->getSubstr(lineContent, START_DELIMIT_TYPE, true);

  if (typeObject.compare("ground") == 0)
    addGroundToMap();
  else if (typeObject.compare("wall") == 0)
    addWallToMap();
  else if (typeObject.compare("box") == 0)
    addBoxToMap();
  else if (typeObject.compare("boxBreakable") == 0)
    addBoxBreakableToMap();
}

void		ParserMap::addGroundToMap()
{
  glm::vec3	position(this->_currentX * 30, 0, this->_currentY * 30);
  glm::vec3	rotation(0, 0, 0);
  glm::vec3	scale(COEFF_SCALE, COEFF_SCALE, COEFF_SCALE);  
  AObject*	object = new Ground(position, rotation, scale);
  
  if (object->initialize() == false)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "error while init ground");
  //this->_map[Coordinates(this->_currentX, this->_currentY)] = object;
  this->_map.insert(std::make_pair(Coordinates(this->_currentX, 
					       this->_currentY), 
				   object));
  this->_listObjects.push_back(object);
}

void		ParserMap::addBoxToMap()
{
  glm::vec3	position(this->_currentX * 30, 0, this->_currentY * 30);
  glm::vec3	rotation(0, 0, 0);
  glm::vec3	scale(COEFF_SCALE, COEFF_SCALE, COEFF_SCALE);  
  AObject*	object = new Box(position, rotation, scale);
   
  this->addGroundToMap();
  if (object->initialize() == false)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "error while init ground");
  //this->_map[Coordinates(this->_currentX, this->_currentY)] = object;
  this->_map.insert(std::make_pair(Coordinates(this->_currentX, 
					       this->_currentY), 
				   object));
  this->_listObjects.push_back(object);
}

void		ParserMap::addBoxBreakableToMap()
{
  glm::vec3	position(this->_currentX * 30, 0, this->_currentY * 30);
  glm::vec3	rotation(0, 0, 0);
  glm::vec3	scale(COEFF_SCALE, COEFF_SCALE, COEFF_SCALE);  
  AObject*	object = new BoxBreakable(position, rotation, scale);
 
  this->addGroundToMap(); 
  if (object->initialize() == false)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "error while init ground");
  //this->_map[Coordinates(this->_currentX, this->_currentY)] = object;
  this->_map.insert(std::make_pair(Coordinates(this->_currentX, 
					       this->_currentY), 
				   object));
  this->_listObjects.push_back(object);
}

void		ParserMap::addWallToMap()
{
  glm::vec3	position(this->_currentX * 30, 0, this->_currentY * 30);
  glm::vec3	rotation(0, 0, 0);
  glm::vec3	scale(COEFF_SCALE, COEFF_SCALE, COEFF_SCALE);
  AObject*	object = new Wall(position, rotation, scale);

  this->addGroundToMap();
  if (object->initialize() == false)
    throw Exception(NO_ERRNO, __LINE__, __FILE__, "error while init wall");
  //this->_map[Coordinates(this->_currentX, this->_currentY)] = object;
  this->_map.insert(std::make_pair(Coordinates(this->_currentX, 
					       this->_currentY), 
				   object));
  this->_listObjects.push_back(object);
}

void		ParserMap::updateMap(std::string lineContent)
{
  if (lineContent.find("y pos=") != std::string::npos)
    this->updateCurrentY(lineContent);
  else if (lineContent.find("x pos=") != std::string::npos)
    this->addObjectToMap(lineContent);
}

void		ParserMap::readLineContent(std::string lineContent, 
					   unsigned int numberLine)
{
  if (numberLine == 2)
    {
      if (lineContent.compare("<map>") != 0)
	throw Exception(NO_ERRNO, __LINE__, __FILE__, "error syntax xml file");
    }    
  else if (numberLine == 3)
    {
      this->setLevel(lineContent);
      this->setDifficulty(lineContent);
    }
  else if (numberLine == 4)
    this->setSize(lineContent);
  else
    this->updateMap(lineContent);
}

void		ParserMap::parse()
{
  unsigned int	numberLine;
  std::string	lineContent;
  
  numberLine = 0;
  while (std::getline(this->_file, lineContent))
    readLineContent(lineContent, ++numberLine);
  // exit(0);
}

int				ParserMap::getLevel() const
{
  return (this->_level);
}

std::string			ParserMap::getDifficulty() const
{
  return (this->_difficulty);
}

int				ParserMap::getSizeWidth() const
{
  return (this->_sizeWidth);
}

int				ParserMap::getSizeHeight() const
{
  return (this->_sizeHeight);
}

// std::map<Coordinates, AObject*>	ParserMap::getMap() const
// {
//   return (this->_map);
// }
