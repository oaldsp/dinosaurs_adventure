#include "Enemy.h"

namespace Creature{
	namespace Entities{

		Enemy::Enemy(CoordF  posTemp, CoordF sizeTemp, ID idTemp, unsigned int lifeTemp, CoordF speedTemp):
		Creature(posTemp, sizeTemp, idTemp, lifeTemp, speedTemp)
		{
			//start();
			time=0;
		}
		
		void Enemy::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case ground:
				moveAway(slamEntity,difference);
				break;
			default:
				break;
			}	
		}
	}//Final do namespace Entities
}//Final do namespace Creature

