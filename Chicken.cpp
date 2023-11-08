#include "Chicken.h"

namespace Creature{
	namespace Entities{

		Chicken::Chicken(CoordF  posTemp):
		Enemy(posTemp, CoordF(C_SIZE_X, C_SIZE_Y)){
			this->getShape()->setTexture("texture/chicken.png");
			this->setID(chicken);
			this->setLife(C_LIFE);
			this->setSpeedX(C_SPEED_X);
			start();
			time=0;
		}

		void Chicken::move(float dT){
			CoordF posTemp = this->getPos();
			time += dT;
			this->getShape()->updatePos(posTemp);
			if(time < 5.0f)
				this->setPos(CoordF(posTemp.x +  C_SPEED_X*dT, posTemp.y + C_SPEED_Y*dT));
			else if (time < 10.0f)
				this->setPos(CoordF(posTemp.x -  C_SPEED_X*dT, posTemp.y + C_SPEED_Y*dT));
			else	
				time = 0;
			
		}

		void Chicken::start(){
			
		}

		void Chicken::collision(Entity* slamEntity, CoordF difference){
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

