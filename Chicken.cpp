#include "Chicken.h"

namespace Entities{
	namespace Creature{

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
			CoordF speedTemp = this->getSpeed();
			time += dT;
			this->getShape()->updatePos(posTemp);
			if(time < 5.0f)
				this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*dT));
			else if (time < 10.0f)
				this->setPos(CoordF(posTemp.x - speedTemp.x*dT, posTemp.y + speedTemp.y*dT));
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
	}//Final do namespace Creature
}//Final do namespace Entities

