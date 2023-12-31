#include "Creature.h"
#include <math.h>

namespace Entities{
	namespace Creature{

		Creature::Creature(CoordF posTemp, CoordF sizeTemp):
		MoveEntity(posTemp, sizeTemp),
		life(100){}

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
				//setSpeedX(0.0f);
			}else{//bateu em y
				if(posThis.y < slamPos.y){//em cima
					//for(int i=0; i<1; i++)
					//	printf("%f\n", difference.y);
					this->setPos(CoordF(posThis.x, posThis.y + difference.y));
				}else{
					//for(int i=0; i<10; i++)
					//	printf("D|");
					this->setPos(CoordF(posThis.x, posThis.y - difference.y));}
				//setSpeedY(0.0f);
			}

		}

		float Creature::getLife() const{
			return life;
		}

		void Creature::setLife(const float lifeTemp){
			life=lifeTemp;
		}
	}//final do namespace Creature
}//final do namespace Entities
