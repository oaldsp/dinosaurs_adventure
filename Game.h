#pragma once

#include "StateMachine.h"
#include "EventsManager.h"
#include "GraphicsManager.h"
#include "StartMenu.h"
#include "EntityList.h"
#include "LevelOne.h"
#include "StateMachine.h"
#include "LevelTwo.h"

class Game: public StateMachine{
private:
	Levels::LevelOne level_one;
	Levels::LevelTwo level_two;
	
	StateMachine* pStateMachine;
	
	Managers::EventsManager* pEvents;
	Managers::GraphicsManager* pGrap; 	

	sf::Clock clk;
	float dT;
public:
	Game();
	~Game() = default;
	
	void exe();
}; 
