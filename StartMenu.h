#pragma once 

#include "Menu.h"
#include "State.h"

class Game;//por causa do include bidirecional

class StartMenu: public State, public Menu{
private:
	Game* pGame;
public:
	StartMenu(Game* gameTemp = NULL);
	~StartMenu() = default;

	//heranca do state
	void start();
	void move(const float dt);
	void plot();
	void reset();
	
	//heranca do menu
	void op1();
	void op2();
	void op3();
	void op4();
};
