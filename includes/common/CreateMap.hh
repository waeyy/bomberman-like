//
// CreateMap.hh for CreateMap.hh in /home/taulei_c/rendu/PAV/cpp_bomberman/sources
// 
// Made by charles tauleigne
// Login   <taulei_c@epitech.net>
// 
// Started on  Thu Jun 18 23:03:49 2015 charles tauleigne
// Last update Thu Jun 18 23:39:03 2015 charles tauleigne
//

#ifndef		_CREATEMAP_HH_
# define	_CREATEMAP_HH_

# include	<string>
# include	<iostream>
# include	<cstring>
# include	<vector>
# include	<stdlib.h>
# include	<fstream>

class		CreateMap
{
private:
  int		_sizeX;
  int		_sizeY;

public:
  CreateMap();
  ~CreateMap();

  int		create_map(int, int);
};

#endif		/* !CREATE_MAP_HH_ */
