#include "Game.h"

using namespace Managers;

Game::Game():
pStateMachine(StateMachine::getInstance()),
pEvents(EventsManager::getInstance()),
pGrap(GraphicsManager::getInstance()),
level_one(),
level_two(),
dT(0.0f)
{
	clk.restart();
	
	//ALOCAR LEVEIS AQUI

	add(static_cast<State*>(new StartMenu(this)));

	//changeState(stateID::menu);

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
