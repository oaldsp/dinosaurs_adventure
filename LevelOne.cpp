#include "LevelOne.h"

namespace Levels{

	LevelOne::LevelOne():
	    Level(level1),
	    finish(0),
	    background(CoordF(0.0f, 0.0f), CoordF(1380.0f, 768.0f)),
	    p1(NULL),
	    p2(NULL)
	    {
		background.setTexture("texture/background.jpg");
		start();
	    }

	    LevelOne::~LevelOne()
	    {

	    }

	    void LevelOne::move(const float dt)
	    {
		pGM->centerView(CoordF(p1->getPos().x, 384.0f));
		list_c.move(dt);
		list_o.move(dt);
		collision_manager.collide();
		background.updatePos(CoordF(p1->getPos().x-700.0f,0.0f));

		if(p1->getPos().x >= 7600.0f)
		    pMachi->changeState(level2);
	    }

	    void LevelOne::plot()
	    {
		draw();
		background.plot();

		list_c.plot();
		list_o.plot();
	    }

	    void LevelOne::createC()
	    {
		std::srand(std::time(NULL));

		Entities::Creature::Chicken* aux = NULL;
		
		int numC= rand()%3 + 4;
		float numP= 8000/(rand()%3 + 7);
		
		for(int i=0;i<numC;i++){
		    aux = new Entities::Creature::Chicken(CoordF((i*numP) + 500.0f + rand()%10, 300.f));
		    list_c.addEntity(static_cast<Entities::Entity*>(aux));
		    list_c.addEntity(static_cast<Entities::Entity*>(aux->getPrct()));

		}
	    }

	    void LevelOne::createP()
	    {
		std::srand(std::time(NULL));

		Entities::Entity* aux = NULL;

		int numO= rand()%3 + 6;
		float numP= 8000/(rand()%5 + 7);

		for(int i=0;i<numO;i++){
		    aux = new Entities::Obstacles::Petroleum(CoordF((i*numP)+ 600.0f + rand()%10, 599.9f), CoordF(150.0f, 15.0f));
		    list_o.addEntity(static_cast<Entities::Entity*>(aux));
		}
	    }

	    void LevelOne::createPlayer()
	    {
		p1 = new Entities::Creature::Player(CoordF(300.f, 250.f));
		p1->getCtrl()->setKeys("W","A","D","S");
		p1->getShape()->setTexture("texture/player1.png");
		list_c.addEntity(static_cast<Entities::Entity*>(p1));
		list_c.addEntity(static_cast<Entities::Entity*>(p1->getPrct()));	
	    }
		
	    void LevelOne::createP2()
	    {
		p2 = new Entities::Creature::Player(CoordF(300.f, 250.f));
		p2->getCtrl()->setKeys("^","<",">","*");
		p2->getShape()->setTexture("texture/player2.png");
		list_c.addEntity(static_cast<Entities::Entity*>(p2));
		list_c.addEntity(static_cast<Entities::Entity*>(p2->getPrct()));
	    }

	    void LevelOne::reset()
	    {

	    }

	    void LevelOne::start()
	    {
		createPlayer();
		createC();
		createP();
	    }
}//FInal do namespace Levels
