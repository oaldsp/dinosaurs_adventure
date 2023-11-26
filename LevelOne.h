#pragma once

#include "Level.h"

class LevelOne : public Level
{
    private:
        int finish;
        StaticAnimation background;
        Entities::Creature::Player* p1;
	Entities::Creature::Player* p2;
    public:
        LevelOne();
        ~LevelOne();
        
        void move(const float dt);
        void plot();
        void reset();

        void createC();
        void createP();
        void createPlayer();
	void createP2();

        void start();
};
