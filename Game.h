#pragma once

#include "StateMachine.h"
#include "EventsManager.h"
#include "GraphicsManager.h"
#include "StartMenu.h"

class Game: public StateMachine{
private:
	//Eventos
	EventsManager* pEvents;

	//grafico	
	Managers::GraphicsManager* pGrap; 	

	sf::Clock clk;
	float dT;
public:
	Game();
	~Game() = default;
	
	void exe();
}; 
