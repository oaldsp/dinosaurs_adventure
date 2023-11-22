#include "LevelOne.h"

LevelOne::LevelOne():
    Level(level1),
    finish(0),
    background(CoordF(-384.0f - 300.0f, 0.0f), CoordF(3*1366.0f, 768.0f))
    {
        //body.setSize(sf::Vector2f(3*1366.f, 768.f));
        //body.setOrigin(sf::Vector2f(-384.f -300.f, 0.f));
        background.setTexture("texture/background.jpg");
    }

    LevelOne::~LevelOne()
    {

    }

    void LevelOne::move(const float dt)
    {
        pGM->centerView(CoordF(list_c[0]->getPos().x, 384.0f));//tem que trocar para o player

        list_c.move(dt);
        list_o.move(dt);

        collision_manager.collide();

    }

    void LevelOne::plot()
    {
        draw();

        list_c.plot();
        list_o.plot();
    }

    void LevelOne::reset()
    {

    }

    void LevelOne::start()
    {

    }