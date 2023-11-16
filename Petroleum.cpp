#include "Petroleum.h"

namespace Entities{
	namespace Obstacles{
		Petroleum::Petroleum(CoordF  posTemp, CoordF sizeTemp):
		Obstacle(posTemp, sizeTemp){
			srand(std::time(NULL));
			viscosity = rand()%11 + 10;
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
			default:		
			break;
			}
		}

		int Petroleum::getAttribute() const{
			return viscosity;
		}
	}//final do namespace Obstacles
}//final do namespace Entities 

