#include "Game.h"

using namespace Managers;

Game::Game():
pGrap(Graphics::getInstance()),
p1(CoordF(200.f,400.f),true),
background(CoordF(0.0f,0.0f), CoordF(1280,720), 1){
	start();
	exe();
}

void Game::start(){
	background.setTexture("texture/background.jpg");
	(p1.getShape()).setTexture("texture/player.png");
	Entities::MoveEntity a;
	a.getShape;
}

void Game::exe(){
	float dt;

	while(pGrap->isWindowOpen()){
		dt = pGrap->updateDeltaTime();
		pGrap->clear();
		
		//p1.move(dt);

		background.plot();
		p1.plot();

		pGrap->display();
	}
}
