#include "Creature.h"

namespace Entities{
	Creature::Creature(CoordF posTemp, CoordF sizeTemp, ID idTemp , unsigned int lifeTemp, CoordF speedTemp):
	MoveEntity(posTemp, sizeTemp, idTemp),
	life(lifeTemp),speed(speedTemp){}

	void Creature::moveAway(Entity* slamEntity, CoordF  difference){
		CoordF slamPos = slamEntity->getPos();
		CoordF posThis = this->getPos();

		if(difference.x > difference.y){//bateu em x
			if(posThis.x > slamPos.x)
				posThis.x -=  difference.x;
			else
				posThis.x += difference.x;
			speed.x =  0.0f;
		}else{//bateu em y
			if(posThis.y > slamPos.y)
				posThis.y -=  difference.y;
			else
				posThis.y += difference.y;
			speed.y =  0.0f;
		}
	}

	void Creature::damage(unsigned int damage){
		life-=damage;
		if(life<=0)
			this->setLive(false);
	}
}//final do namespace Entities 
