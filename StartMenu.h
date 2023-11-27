#pragma once 

#include "Menu.h"
#include "Level.h"
#include "State.h"
#include <vector>

class Game;//por causa do include bidirecional

class StartMenu: public State, public Menu{
private:
	Game* pGame;
	vector<Levels::Level*> levels;
public:
	StartMenu(Game* gameTemp = NULL);
	~StartMenu() = default;

	void addLevel(Levels::Level* levelTemp);

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
