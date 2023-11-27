#include "LevelTwo.h"

namespace Levels{

	LevelTwo::LevelTwo():
	    Level(level2),
	    finish(0),
	    background(CoordF(0.0f, 0.0f), CoordF(1380.0f, 768.0f)),
	    p1(NULL),
	    p2(NULL)
	    {
		background.setTexture("texture/background2.png");
		start();
	    }

	    LevelTwo::~LevelTwo()
	    {

	    }

	    void LevelTwo::move(const float dt)
	    {
		pGM->centerView(CoordF(p1->getPos().x, 384.0f));//tem que trocar para o player
		list_c.move(dt);
		list_o.move(dt);

		collision_manager.collide();
		background.updatePos(CoordF(p1->getPos().x-700.0f,0.0f));
		
		if(p1->getPos().x >= 7600.0f){
			cout << "VICTORY" << endl;
			exit(1);
		}	
	    }

	    void LevelTwo::plot()
	    {
		draw();
		background.plot();

		list_o.plot();
		list_c.plot();
	    }

	    void LevelTwo::createR()
	    {
		std::srand(std::time(NULL));

		Entities::Entity* aux = NULL;

		float nextPos = 8000/(rand()%10 + 5);
		int numR = rand()%2 + 3;
		
		for(int i=0; i < numR ; i++){
			aux = new Entities::Creature::Rooster(CoordF((i*nextPos) + 1800.0f + rand()%10, 300.f));
			list_c.addEntity(static_cast<Entities::Entity*>(aux));
		}
	    }

	    void LevelTwo::createM()
	    {
		std::srand(std::time(NULL));

		Entities::Entity* aux = NULL;

		int numO = rand()%3  + 4;
		float numP= 8000/(rand()%3  + 7);

	       for(int i=0;i<numO;i++){
		    aux = new Entities::Obstacles::Meteor(CoordF((i*numP)+637.0f, 590.0f));
		    list_o.addEntity(static_cast<Entities::Entity*>(aux));
		}
	    }

	    void LevelTwo::createP()
	    {
		p1 = new Entities::Creature::Player(CoordF(300.0f, 250.0f));
		p1->getCtrl()->setKeys("W","A","D","S");
		p1->getShape()->setTexture("texture/player1.png");
		list_c.addEntity(static_cast<Entities::Entity*>(p1));
		list_c.addEntity(static_cast<Entities::Entity*>(p1->getPrct()));
	    }
	     
	    void LevelTwo::createP2()
	    {
		p2 = new Entities::Creature::Player(CoordF(300.0f, 250.0f));
		p2->getCtrl()->setKeys("^","<",">","*");
		p2->getShape()->setTexture("texture/player2.png");
		list_c.addEntity(static_cast<Entities::Entity*>(p2));
		list_c.addEntity(static_cast<Entities::Entity*>(p2->getPrct()));
	    }

	    void LevelTwo::reset()
	    {
		//list_c.clear();
		//list_o.clear();
		//start();
	    }

	    void LevelTwo::start()
	    {
		createP();
		createM();
		createR();
	    }
}//FInal do namespace Levels
