all:
	g++ entity.cpp player.cpp game.cpp main.cpp coord.h -o play -lsfml-graphics -lsfml-window -lsfml-system 	
