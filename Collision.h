#pragma once

#include "Entity.h"
#include "EntityList.h"

/*
	Codigo reutilizado de "Burda Canal"
	Link: https://youtu.be/mxZMK7ZqFtE?si=xO72bRPehRyzzAAk
*/


namespace States {
    class Level;
} // namespace States


namespace Managers {

    class Collision {
    private:
        List::EntityList* movingEntities;
        List::EntityList* staticEntities;
        //States::Level* plvl;

    public:
        Collision(List::EntityList* movingEntities, List::EntityList* staticEntities/*, States::Level* plvl*/);

        ~Collision();

        void collide();

        void clear();
    };

} // namespace Managers
