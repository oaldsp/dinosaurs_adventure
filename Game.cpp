#include "Game.h"

using namespace Managers;

Game::Game():
pStateMachine(StateMachine::getInstance()),
pEvents(EventsManager::getInstance()),
pGrap(GraphicsManager::getInstance()),
level_one(),
level_two()
/*background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),//pos,size
pp1(&p1),
p1(CoordF(300.f,250.f), &pp1),
c1(CoordF(100.0f, 100.f)),
pe1(&ce1),
ce1(CoordF(1100.0f, 100.f), &pe1),
r1(CoordF(100.0f-100.0f,195.f - 100.0f)),
e1(CoordF(600.0f,300.0f), CoordF(250.0f,50.0f)),//pos,size
m1(CoordF(250.0f, 285.0f)),
g1(CoordF(0.0f,300.0f), CoordF(600.0f,50.0f)),
g2(CoordF(850.0f,300.0f), CoordF(900.0f,50.0f)),
w1(CoordF(1400.0f,0.0f), CoordF(50.0f,300.0f)),
w2(CoordF(0.0f,250.0f), CoordF(50.0f,50.0f))*/{
	printf("FLAGGGG");
	start();
	exe();
}

void Game::start(){
}

void Game::exe(){
	float dt;

	while(pGrap->isWindowOpen()){
		dt = pGrap->updateDeltaTime();
		pGrap->clear();

		pEvents->libraryEvents();
		//printf("\n");
		pStateMachine->exe(dt);

		pGrap->display();
	}
}
