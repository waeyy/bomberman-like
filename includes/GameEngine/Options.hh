//
// Options.hh for Option.h in /home/taulei_c/rendu/PAV/cpp_bomberman/src
// 
// Made by charles tauleigne
// Login   <taulei_c@epitech.net>
// 
// Started on  Fri May 22 18:49:51 2015 charles tauleigne
// Last update Tue Jun 23 15:26:05 2015 SOIDIKI Djamil
//

#ifndef		OPTIONS_HH_
# define	OPTIONS_HH_

# include	<iostream>
# include	<string>

class		Options
{
private :
  unsigned int	_nb_players;
  unsigned int	_nb_ia;
  unsigned int	_ia_level;
  unsigned int	_height_map;
  unsigned int	_width_map;
  std::string	_map;
  bool		_randommap;

public :
  Options(unsigned int, unsigned int, unsigned int, unsigned int, bool);
  ~Options();

  void		setNbPlayers(unsigned int);
  void		setNbIa(unsigned int);
  void		setIALevel(unsigned int);
  void		setHeightMap(unsigned int);
  void		setWidthMap(unsigned int);
  void		setMap(std::string);
  void		setRandommap(bool);

  unsigned int	getNbPlayers() const;
  unsigned int	getNbIa() const;
  unsigned int	getIALevel() const;
  unsigned int	getHeightMap() const;
  unsigned int	getWidthMap() const;
  std::string	getMap() const;
  bool		getRandommap() const;
};

#endif		/* !OPTION_HH_ */
