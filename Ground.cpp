#include "Ground.h"

namespace Entities{
	namespace Obstacles{
		Ground::Ground(CoordF  posTemp, CoordF sizeTemp):
		Obstacle(posTemp, sizeTemp){
			srand(std::time(NULL));
			friction= rand()%3 + 1;
			start();
		}

		void Ground::move(float dT){
			this->getShape()->updatePos(getPos());
		}

		void Ground::start(){
			this->getShape()->setTexture("texture/ground.jpg");
			this->setID(ground);
		}

		void Ground::collision(Entity* slamEntity, CoordF difference){	
		}

		int Ground::getAttribute() const{
			return friction;	
		}
	}//final do namespace Obstacles
}//final do namespace Entities 
