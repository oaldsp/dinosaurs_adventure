#include "Game.h"

using namespace Managers;

Game::Game():
GC(&mE,&sE),
pGrap(Graphics::getInstance()),
background(CoordF(0.0f,0.0f), CoordF(1280,720)),
p1(CoordF(200.f,100.f),true),
g1(CoordF(250.0f,300.0f)){
	start();
	exe();
}

void Game::start(){
	background.setTexture("texture/background.jpg");
	mE.addEntity(&p1);
	sE.addEntity(&g1);
}

void Game::exe(){
	float dt;

	while(pGrap->isWindowOpen()){
		dt = pGrap->updateDeltaTime();
		pGrap->clear();
		
		p1.move(dt);

		GC.collide();
		GC.clear();	

		background.plot();
		p1.plot();
		g1.plot();

		pGrap->display();
	}
}
