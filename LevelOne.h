#pragma once

#include "Level.h"

class LevelOne : public Level
{
    private:
        int finish;
        StaticAnimation background;
    public:
        LevelOne();
        ~LevelOne();
        
        void move(const float dt);
        void plot();
        void reset();

        void start();
};