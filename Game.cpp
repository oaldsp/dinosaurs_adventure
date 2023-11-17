#include "Game.h"

using namespace Managers;

Game::Game():
GC(&mE,&sE),
pEvents(EventsManager::getInstance()),
pGrap(GraphicsManager::getInstance()),
background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),
pp1(&p1),
p1(CoordF(300.f,250.f), &pp1),
c1(CoordF(100.0f, 100.f)),
pe1(&ce1),
ce1(CoordF(1100.0f, 100.f), &pe1),
r1(CoordF(100.0f-100.0f,195.f - 100.0f)),
e1(CoordF(600.0f,300.0f), CoordF(250.0f,50.0f)),
m1(CoordF(250.0f, 285.0f)),
g1(CoordF(0.0f,300.0f), CoordF(600.0f,50.0f)),
g2(CoordF(850.0f,300.0f), CoordF(900.0f,50.0f)),
w1(CoordF(1400.0f,0.0f), CoordF(50.0f,300.0f)),
w2(CoordF(0.0f,250.0f), CoordF(50.0f,50.0f)){
	start();
	exe();
}

void Game::start(){
	background.setTexture("texture/background.jpg");

	p1.getCtrl()->setKeys("W","A","D","S");

	mE.addEntity(&p1);
	mE.addEntity(&c1);
	mE.addEntity(&ce1);
	mE.addEntity(&r1);
	mE.addEntity(&pp1);
	mE.addEntity(&pe1);

	sE.addEntity(&e1);
	sE.addEntity(&m1);
	sE.addEntity(&g1);
	sE.addEntity(&g2);
	sE.addEntity(&w1);
	sE.addEntity(&w2);
}

void Game::exe(){
	float dt;

	while(pGrap->isWindowOpen()){
		dt = pGrap->updateDeltaTime();
		pGrap->clear();
		pGrap->centerView(CoordF(p1.getPos().x, 384.0f));

		mE.move(dt);
		sE.move(dt);

		pEvents->libraryEvents();
		GC.collide();

		background.plot();
		
		mE.plot();
		sE.plot();

		pGrap->display();
	}
}
