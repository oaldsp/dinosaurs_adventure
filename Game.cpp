#include "Game.h"

using namespace Managers;

Game::Game():
GC(&mE,&sE),
pEvents(Events::getInstance()),
pGrap(Graphics::getInstance()),
background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),
p1(CoordF(300.f,250.f)),
c1(CoordF(0.0f,230.f)),
g1(CoordF(0.0f,300.0f), CoordF(600.0f,50.0f)),
w1(CoordF(550.0f,250.0f), CoordF(50.0f,50.0f)),
w2(CoordF(0.0f,250.0f), CoordF(50.0f,50.0f)){
	start();
	exe();
}

void Game::start(){
	background.setTexture("texture/background.jpg");
	
	p1.getCtrl()->setKeys("W","A","D","S");

	mE.addEntity(&p1);
	mE.addEntity(&c1);

	sE.addEntity(&g1);
	sE.addEntity(&w1);
	sE.addEntity(&w2);
}

void Game::exe(){
	float dt;

	while(pGrap->isWindowOpen()){
		dt = pGrap->updateDeltaTime();
		pGrap->clear();
		pGrap->centerView(CoordF(p1.getPos().x, 384.0f));

		c1.move(dt);
		p1.move(dt);

		pEvents->libraryEvents();
		GC.collide();

		background.plot();
		p1.plot();
		c1.plot();
		g1.plot();
		w1.plot();
		w2.plot();

		pGrap->display();
	}
}
