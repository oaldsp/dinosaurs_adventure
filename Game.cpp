#include "Game.h"

using namespace Managers;

Game::Game():StateMachine(),
pEvents(EventsManager::getInstance()),
pGrap(GraphicsManager::getInstance()), dT(0.0f){
	clk.restart();
	
	//ALOCAR LEVEIS AQUI

	add(static_cast<State*>(new StartMenu(this)));

	changeState(stateID::menu);
	exe();
}

void Game::exe(){
	while(pGrap->isWindowOpen()){
		pEvents->libraryEvents();
		pGrap->clear();

		dT = pGrap->updateDeltaTime();
			
		this->plot();//plota estado atual

		pGrap->display();
	}
}
