//
// CreateMap.cpp for CreateMap.cpp in /home/taulei_c/rendu/PAV/cpp_bomberman/sources
// 
// Made by charles tauleigne
// Login   <taulei_c@epitech.net>
// 
// Started on  Thu Jun 18 23:02:50 2015 charles tauleigne
// Last update Tue Jun 23 16:00:43 2015 SOIDIKI Djamil
//

#include	"../../includes/common/CreateMap.hh"

CreateMap::CreateMap()
{
  _sizeX = 0;
  _sizeY = 0;
}

CreateMap::~CreateMap()
{
}

int		CreateMap::create_map(int x, int y)
{
  std::ofstream	file("map/random.xml");
  int		i = -1;
  int		j = 0;

  _sizeX = x;
  _sizeY = y;
  if(file.is_open())
    {
      file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<map>\n"
	   << "<level number=\"1\" difficulty=\"easy\"/>\n"
	   << "<size x=\"" << _sizeX << "\" y=\"" << _sizeY << "\"/>" << std::endl;
    }
  while (++i < _sizeY)
    {
      file << "<y pos=\"" << i << "\">" << std::endl;
      j = -1;
      while (++j < _sizeX)
	{
	  if (i == 0 || (i + 1) == _sizeX || j == 0 || (j + 1) == _sizeY)
	    file << "<x pos=\"" << j << "\" type=\"wall\" />"
		 << std::endl;
	  else
	    {
	      if (((j % 2) == 0) && ((i % 2) == 0))
		file << "<x pos=\"" << j << "\" type=\"box\" />"
		     << std::endl;
	      else
		file << "<x pos=\"" << j << "\" type=\"ground\" />"
		     << std::endl;
	    }
	}
      file << "</y>" << std::endl;
    }
  file << "</map>" << std::endl;
  return (0);
}
