#include "Enemy.h"

namespace Entities{
	namespace Creature{

		unsigned int Enemy::enemyTotal = 0;

		Enemy::Enemy(CoordF  posTemp, CoordF sizeTemp):
		Creature(posTemp, sizeTemp)
		{
			enemyTotal++;
		}
	
		Enemy::~Enemy(){
			enemyTotal--;
		}

		void Enemy::damage(const float damage){
			setLife(getLife() - damage);
			if(getLife() <= 0.0f)
				this->setLive(false); 
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
	}//Final do namespace Creature
}//Final do namespace Entities

