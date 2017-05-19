//
// Coordinates.hh for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/includes
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Jun 11 10:13:09 2015 SOIDIKI Djamil
// Last update Mon Jun 22 19:34:33 2015 SOIDIKI Djamil
//

#ifndef		_COORDINATES_HH_
# define	_COORDINATES_HH_

class		Coordinates {

protected:
  int		_x;
  int		_y;
  
public:
  Coordinates(int x = 0, int y = 0);
  Coordinates(const Coordinates&);
  ~Coordinates();
 
  int		getX() const;
  int		getY() const;

  void		setX(int);
  void		setY(int);

  Coordinates&	operator=(const Coordinates&);
  Coordinates	operator+(const Coordinates&) const;
  bool		operator<(const Coordinates&) const;
};

#endif		/* _COORDINATES_HH_ */
