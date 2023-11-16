#include "CollisionManager.h"

#include "MoveEntity.h"
//#include "StaticEntity.h"
#include <math.h>

/*
	Codigo reutilizado de "Burda Canal"
	Link: https://youtu.be/mxZMK7ZqFtE?si=xO72bRPehRyzzAAk
*/

namespace Managers {

    CollisionManager::CollisionManager(List::EntityList* movingEntities, List::EntityList* staticEntities/*, States::Level* plvl*/) :
    movingEntities(movingEntities),
    staticEntities(staticEntities)
    /*,plvl(plvl) */{ }

    CollisionManager::~CollisionManager() {
        movingEntities = nullptr;
        staticEntities = nullptr;
    }

    void CollisionManager::collide() {
        Entities::Entity* ent1 = nullptr;
        Entities::Entity* ent2 = nullptr;
        CoordF intersect;
        CoordF centerDistance;
        int i, j;

        /* Collide non-moving entities with moving entities */
        for (i = 0; i < staticEntities->getSize(); i++) {
            for (j = 0; j < movingEntities->getSize(); j++) {
                ent1 = (*staticEntities)[i];
                ent2 = (*movingEntities)[j];
		//printf("|%d,%d|", i, j);	
                centerDistance.x = (ent2->getPos().x + ent2->getSize().x / 2.0f) - (ent1->getPos().x + ent1->getSize().x / 2.0f);
		//if(centerDistance.x<0.0f){ 
		//	centerDistance.x*=-1;
		//	
		//printf("AAAAA");
		//}	
                centerDistance.y = (ent2->getPos().y + ent2->getSize().y / 2.0f) - (ent1->getPos().y + ent1->getSize().y / 2.0f);

                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);	
		//printf("|%.0f,%.0f|",centerDistance.x,centerDistance.y);
                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...
			//for(int i=0;i<100000;i++)
			//	printf("Bateu");
			ent2->collision(ent1, intersect);
                }
            }
        }

        /* Collide moving entities with moving entities - diagonally */
        for (i = 0; i < movingEntities->getSize(); i++) {
            for (j = i + 1; j < movingEntities->getSize(); j++) {
                ent1 = (*movingEntities)[i];
                ent2 = (*movingEntities)[j];
		//printf("|%d,%d|", i, j);	
                centerDistance.x = (ent2->getPos().x + ent2->getSize().x / 2.0f) - (ent1->getPos().x + ent1->getSize().x / 2.0f);
                centerDistance.y = (ent2->getPos().y + ent2->getSize().y / 2.0f) - (ent1->getPos().y + ent1->getSize().y / 2.0f);

                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);

                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide..
		    //for(int i=0;i<100000;i++)
		        //printf("Bateu em outro");
                    ent2->collision(ent1, intersect);
                    ent1->collision(ent2, intersect);
                }
            }
        }

        clear();
    }

    /* Function to deallocate entities after collision */
    void CollisionManager::clear() {
        Entities::MoveEntity* pAux = nullptr;
        for (int i = 0; i < movingEntities->getSize(); i++) {
            pAux = static_cast<Entities::MoveEntity*>((*movingEntities)[i]);
            if (pAux != nullptr) {
                if (!pAux->getLive()) {
                    //if (pAux->getID() != Entities::ID::coin)
                        //plvl->coinBomb(pAux->getLive());
                    movingEntities->removeEntity(pAux);
                    i--;
                    if (i < 0)
                        i = -1;
                }
            }
        }
    }

} // namespace Managers
