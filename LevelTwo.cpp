#include "LevelTwo.h"

LevelTwo::LevelTwo():
    Level(level2),
    finish(0),
    background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f)),
    pp1(&p1),
    p1(CoordF(300.f,250.f), &pp1)
    {
        //printf("    LEVEL   ");
        background.setTexture("texture/background.jpg");
        start();
    }

    LevelTwo::~LevelTwo()
    {

    }

    void LevelTwo::move(const float dt)
    {
        pGM->centerView(CoordF(p1.getPos().x, 384.0f));//tem que trocar para o player
        //printf("dentro de level");
        list_c.move(dt);
        list_o.move(dt);

        collision_manager.collide();
        background.updatePos(CoordF(p1.getPos().x-700.0f,0.0f));

    }

    void LevelTwo::plot()
    {
        draw();
        background.plot();

        list_c.plot();
        list_o.plot();
    }

    void LevelTwo::createR()
    {
        std::srand(std::time(NULL));

        Entities::Entity* aux = NULL;

        float numP=0.0;
        
        while(numP<8000){
            numP = rand()%9000;
        }

        aux = new Entities::Creature::Rooster(CoordF((numP)+0.0f, 300.f));
        list_c.addEntity(static_cast<Entities::Entity*>(aux));
        
        //printf("    EM createR    ");
    }

    void LevelTwo::createM()
    {
        std::srand(std::time(NULL));

        Entities::Entity* aux = NULL;

        int numO=0;
        float numP=0.0;

        while(numO<4 || numP<7){
            numO = rand()%7;
            numP= rand()%10;
        }
        numP=6000/numP;

        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Meteor(CoordF((i*numP)+637.0f,565.0f));
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
        //printf("    EM START    ");
        createP();
        createM();
        createR();
    }