#pragma once

#include "Level.h"

class LevelTwo : public Level
{
    private:
        int finish;
        StaticAnimation background;
        Entities::Creature::Player p1;
    	Entities::Projectile pp1;
    public:
        LevelTwo();
        ~LevelTwo();
        
        void move(const float dt);
        void plot();
        void reset();

        void createP();
        void createR();
        void createM();

        void start();
};
