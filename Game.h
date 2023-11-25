#pragma once

#include "StateMachine.h"
#include "EventsManager.h"
//<<<<<<< HEAD
#include "GraphicsManager.h"
#include "StartMenu.h"
//=======
#include "EntityList.h"
#include "LevelOne.h"
#include "StateMachine.h"
#include "LevelTwo.h"
//>>>>>>> nivel

class Game: public StateMachine{
private:
	LevelOne level_one;
	LevelTwo level_two;
	
	EventsManager* pEvents;
	StateMachine* pStateMachine;

	//grafico	
	Managers::GraphicsManager* pGrap; 	

	sf::Clock clk;
	float dT;
public:
	Game();
	~Game() = default;
	
	void exe();
}; 
