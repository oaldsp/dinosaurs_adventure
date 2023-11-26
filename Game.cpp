#include "Game.h"

using namespace Managers;

Game::Game():
pStateMachine(StateMachine::getInstance()),
pEvents(EventsManager::getInstance()),
pGrap(GraphicsManager::getInstance()),
level_one(),
level_two()
{
	clk.restart();
	
	StartMenu* aux = new StartMenu(this);
	add(static_cast<State*>(aux));
	aux->addLevel(&level_one);
	aux->addLevel(&level_two);

	exe();
}


void Game::exe(){
	while(pGrap->isWindowOpen()){
		dT = pGrap->updateDeltaTime();
		pGrap->clear();

		pEvents->libraryEvents();
		
		pStateMachine->exe(dT);

		pGrap->display();
	}
}
