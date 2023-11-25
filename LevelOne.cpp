#include "LevelOne.h"

LevelOne::LevelOne():
    Level(level1),
    finish(0),
    background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),
    pp1(&p1),
    p1(CoordF(300.f,250.f), &pp1)
    {
        //printf("    LEVEL   ");
        background.setTexture("texture/background.jpg");
        start();
    }

    LevelOne::~LevelOne()
    {

    }

    void LevelOne::move(const float dt)
    {
        pGM->centerView(CoordF(p1.getPos().x, 384.0f));
        //printf("dentro de level");
        list_c.move(dt);
        list_o.move(dt);
        std::cout<<p1.getPos().x<<std::endl;
        collision_manager.collide();
        background.updatePos(CoordF(p1.getPos().x-700.0f,0.0f));

        if(p1.getPos().x >= 7000.0)
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

        Entities::Entity* aux = NULL;

        int numC=0;
        float numP=0.0;
        
        while(numC<4 || numP<7){
            numC = rand()%7;
            numP = rand()%10;
        }
        numP =8000/numP;

        for(int i=0;i<numC;i++){
            aux = new Entities::Creature::Chicken(CoordF((i*numP)+500.0f, 300.f));
            list_c.addEntity(static_cast<Entities::Entity*>(aux));
        }
        //printf("    EM createC    ");
    }

    void LevelOne::createP()
    {
        std::srand(std::time(NULL));

        Entities::Entity* aux = NULL;

        int numO=0;
        float numP=0.0;

        while(numO<4 || numP<7){
            numO = rand()%7;
            numP= rand()%12;
        }
        numP=8000/numP;

        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Petroleum(CoordF((i*numP)+600.0f,600.0f), CoordF(150.0f,50.0f));
            list_o.addEntity(static_cast<Entities::Entity*>(aux));
        }
        //printf("    EM createp    ");
    }

    void LevelOne::createPlayer()
    {
        p1.getCtrl()->setKeys("W","A","D","S");
        list_c.addEntity(static_cast<Entities::Entity*>(&p1));
    }

    void LevelOne::reset()
    {

    }

    void LevelOne::start()
    {
        //printf("    EM START    ");
        createPlayer();
        createC();
        createP();
    }