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

    class CollisionManager{
    private:
        List::EntityList* movingEntities;
        List::EntityList* staticEntities;
        //States::Level* plvl;

    public:
        CollisionManager(List::EntityList* movingEntities, List::EntityList* staticEntities/*, States::Level* plvl*/);

        ~CollisionManager();

        void collide();

        void clear();
    };

} // namespace Managers
