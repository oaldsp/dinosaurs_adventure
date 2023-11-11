#include "Creature.h"
#include <math.h>

namespace Entities{
	namespace Creature{

		Creature::Creature(CoordF posTemp, CoordF sizeTemp):
		MoveEntity(posTemp, sizeTemp),
		life(10),speed(CoordF(0.0f, G)){}

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
				speed.x *= -1.0f;
			}else{//bateu em y
				if(posThis.y < slamPos.y){//em cima
					//for(int i=0; i<1; i++)
					//	printf("%f\n", difference.y);
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

		unsigned int Creature::getLife() const{
			return life;
		}

		CoordF Creature::getSpeed() const{
			return speed; 
		}

		void Creature::setLife(unsigned lifeTemp){
			life=lifeTemp;
		}

		void Creature::setSpeedX(float xTemp){
			speed.x = xTemp;
		}	
		
		void Creature::setSpeedY(float yTemp){
			speed.y = yTemp;
		}

	}//final do namespace Creature
}//final do namespace Entities
