#include "Enemy.h"

namespace Creature{
	namespace Entities{

		Enemy::Enemy(CoordF  posTemp, CoordF sizeTemp):
		Creature(posTemp, sizeTemp)
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

