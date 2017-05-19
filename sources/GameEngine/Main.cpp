//
// Main.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Thu Jun 11 09:58:03 2015 SOIDIKI Djamil
// Last update Tue Jun 23 15:14:28 2015 SOIDIKI Djamil
//

#include	<QtGui/QApplication>
#include	<cstdlib>
#include	<iostream>
#include	"../../includes/common/Exception.hh"
#include	"../../includes/GameEngine/GameEngine.hh"
#include	"../../includes/GameEngine/Options.hh"
#include        "../../includes/GraphicEngine/IGraphic.hh"
#include	"../../includes/common/ParserMap.hh"
#include	"../../includes/common/launcher.h"

int		main(int argc, char** argv)
{
  try
    {
      QApplication	a(argc, argv);
      Launcher		w;
      
      w.show();
      a.exec();
      system("clear");
    }
  catch (const Exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}
