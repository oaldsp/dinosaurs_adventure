#include "Creature.h"

namespace Entities{
	Creature::Creature(CoordF posTemp, CoordF sizeTemp, ID idTemp , unsigned int lifeTemp, CoordF speedTemp):
	MoveEntity(posTemp, sizeTemp, idTemp),
	life(lifeTemp),speed(speedTemp){}

	void Creature::moveAway(Entity* slamEntity, CoordF  difference){
		CoordF slamPos = slamEntity->getPos();
		CoordF posThis = this->getPos();

		if(difference.x > difference.y){//bateu em x
			if(posThis.x < slamPos.x){//na esquerda
				//for(int i=0; i<10; i++)
				//	printf("A|");
				this->setPos(CoordF(posThis.x + difference.x, posThis.y));
			}else{
				//for(int i=0; i<10; i++)
				//	printf("B|");
				this->setPos(CoordF(posThis.x - difference.x, posThis.y));
			}
			speed.x = 0.0f;
		}else{//bateu em y
			if(posThis.y < slamPos.y){//em cima
				//for(int i=0; i<10; i++)
				//	printf("C|");
				this->setPos(CoordF(posThis.x, posThis.y + difference.y));
			}else{
				//for(int i=0; i<10; i++)
				//	printf("D|");
				this->setPos(CoordF(posThis.x, posThis.y - difference.y));
			}
			speed.y = 0.0f;
		}
	}

	void Creature::damage(unsigned int damage){
		life-=damage;
		if(life<=0)
			this->setLive(false);
	}
}//final do namespace Entities 
