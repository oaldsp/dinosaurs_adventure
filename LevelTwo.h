#pragma once

#include "Level.h"

class LevelTwo : public Level
{
    private:
        int finish;
        StaticAnimation background;
        Entities::Creature::Player* p1;
	Entities::Creature::Player* p2;
    public:
        LevelTwo();
        ~LevelTwo();
        
        void move(const float dt);
        void plot();
        void reset();

        void createP();
	void createP2();
        void createR();
        void createM();

        void start();
};
