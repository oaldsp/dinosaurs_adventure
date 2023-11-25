#include "LevelTwo.h"

LevelTwo::LevelTwo():
    Level(level2),
    finish(0),
    background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),
    pp1(&p1),
    p1(CoordF(300.f,250.f), &pp1)
    {
        background.setTexture("texture/background.jpg");
        start();
    }

    LevelTwo::~LevelTwo()
    {

    }

    void LevelTwo::move(const float dt)
    {
        pGM->centerView(CoordF(p1.getPos().x, 384.0f));//tem que trocar para o player
        list_c.move(dt);
        list_o.move(dt);

        collision_manager.collide();
        background.updatePos(CoordF(p1.getPos().x-700.0f,0.0f));
	
	if(p1.getPos().x >= 7600.0f){
		cout << "VOCE GANHOU" << endl;
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
        //printf("    EM createM    ");
    }

    void LevelTwo::createP()
    {
        p1.getCtrl()->setKeys("W","A","D","S");
        list_c.addEntity(static_cast<Entities::Entity*>(&p1));
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
