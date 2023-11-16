#include "Game.h"

using namespace Managers;

Game::Game():
GC(&mE,&sE),
pEvents(EventsManager::getInstance()),
pGrap(GraphicsManager::getInstance()),
background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),
p1(CoordF(300.f,250.f), &pp1),
pp1(&p1),
c1(CoordF(0.0f, 220.f)),
ce1(CoordF(1050.0f, 220.f)),
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

		c1.move(dt);
		ce1.move(dt);
		p1.move(dt);
		pp1.move(dt);
		//r1.move(dt);

		pEvents->libraryEvents();
		GC.collide();

		background.plot();
		p1.plot();
		pp1.plot();
		c1.plot();
		ce1.plot();
		r1.plot();
		e1.plot();
		m1.plot();
		g1.plot();
		g2.plot();
		w1.plot();
		w2.plot();
		//mE.plot();
		//sE.plot();

		pGrap->display();
	}
}
