#include "game.h"

using namespace Managers;

Game::Game():pGrap(Graphics::getInstance()){
	exe();
}

Game::~Game(){}

void Game::exe(){
	while(pGrap->isWindowOpen()){
		pGrap->updateDeltaTime();
		pGrap->clear();
		pGrap->display();
	}
}
