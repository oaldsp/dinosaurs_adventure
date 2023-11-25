#pragma once

#include "Level.h"

class LevelOne : public Level
{
    private:
        int finish;
        StaticAnimation background;
        Entities::Creature::Player p1;
    	Entities::Projectile pp1;
    public:
        LevelOne();
        ~LevelOne();
        
        void move(const float dt);
        void plot();
        void reset();

        void createC();
        void createP();
        void createPlayer();

        void start();
};