##
## Makefile for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman
## 
## Made by SOIDIKI Djamil
## Login   <soidik_d@epitech.net>
## 
## Started on  Thu Jun 11 09:50:21 2015 SOIDIKI Djamil
## Last update Tue Jun 23 15:33:26 2015 SOIDIKI Djamil
##

PATH_S_GAME	=	sources/GameEngine/

PATH_S_GRAPH	=	sources/GraphicEngine/

PATH_S_COMM	=	sources/common/

PATH_I_GAME	=	includes/GameEngine/

PATH_I_GRAPH	=	includes/GraphicEngine/

PATH_I_COMM	=	includes/common/

PATH_L		=	libraries/

NAME		=	bomberman

SRCS_GAME	=	$(PATH_S_GAME)Main.cpp \
			$(PATH_S_GAME)Coordinates.cpp \
			$(PATH_S_GAME)Options.cpp \
			$(PATH_S_GAME)GameEngine.cpp

SRCS_GRAPH	=	$(PATH_S_GRAPH)Box.cpp \
			$(PATH_S_GRAPH)BoxBreakable.cpp \
			$(PATH_S_GRAPH)Bomb.cpp \
			$(PATH_S_GRAPH)IA.cpp \
			$(PATH_S_GRAPH)Wall.cpp \
			$(PATH_S_GRAPH)Explosion.cpp \
			$(PATH_S_GRAPH)Character.cpp \
			$(PATH_S_GRAPH)Camera.cpp \
			$(PATH_S_GRAPH)Ground.cpp \
			$(PATH_S_GRAPH)launcher.cpp \
			$(PATH_S_GRAPH)moc_launcher.cpp

SRCS_COMM	=	$(PATH_S_COMM)Exception.cpp \
			$(PATH_S_COMM)AObject.cpp \
			$(PATH_S_COMM)Parser.cpp \
			$(PATH_S_COMM)ParserMap.cpp \
			$(PATH_S_COMM)CreateMap.cpp

OBJS_GAME	=	$(SRCS_GAME:.cpp=.o)

OBJS_GRAPH	=	$(SRCS_GRAPH:.cpp=.o)

OBJS_COMM	=	$(SRCS_COMM:.cpp=.o)

OBJS		=	$(OBJS_GAME) $(OBJS_GRAPH) $(OBJS_COMM)

TEMP		=	$(PATH_S_GAME)*~ $(PATH_S_GRAPH)*~ $(PATH_S_COMM)*~ $(PATH_I_GAME)*~ $(PATH_I_GRAPH)*~ $(PATH_I_COMM)*~ *~

GDLFLAG		=	-lgdl_gl -lGL -lGLEW -ldl -lrt -lSDL2 -lfbxsdk

QT_FLAG		=	-I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.

QT_FLAG2	=	-L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore

QT_FLAG3	=	-DQT_SHARED -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -DQT_GUI_LIB -DQT_CORE_LIB

QT_FLAG4	=	-m64 -pipe -O2 -Wall -W -D_REENTRANT -DQT_WEBKIT -DQT_NO_DEBUG

GDLFLAG         =       -lgdl_gl -lGL -lGLEW -ldl -lrt -lSDL2 -lfbxsdk

QTFLAGS         =       $(QT_FLAG) $(QT_FLAG2) $(QT_FLAG3) $(QT_FLAG4)

CXXFLAGS 	=	-Wall -Wextra -Werror $(QTFLAGS)

all:			$(NAME)

$(NAME):		$(OBJS)
			g++ $(QTFLAGS) -o $(NAME) $(OBJS) $(GDLFLAG) -lpthread

clean:
			rm -f $(OBJS) $(TEMP)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

norm:			re
			rm -f $(OBJS)
