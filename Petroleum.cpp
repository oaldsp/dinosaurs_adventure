#include "Petroleum.h"

namespace Entities{
	namespace Obstacles{
		Petroleum::Petroleum(CoordF  posTemp, CoordF sizeTemp):
		Obstacle(posTemp, sizeTemp){
			srand(std::time(NULL));
			viscosity = rand()%10 +1;
			start();
		}

		void Petroleum::move(float dT){
			this->getShape()->updatePos(getPos());
		}

		void Petroleum::start(){
			this->getShape()->setTexture("texture/petroleum.jpg");
			this->setID(petroleum);
		}

		void Petroleum::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){
			case player:
				slamEntity->setSpeedX(getSpeed().x/((float)viscosity));		
			break;
			}
		}
	}//final do namespace Obstacles
}//final do namespace Entities 

