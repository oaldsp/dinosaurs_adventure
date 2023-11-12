#include "Ground.h"

namespace Entities{
	namespace Obstacles{
		Ground::Ground(CoordF  posTemp, CoordF sizeTemp):
		StaticEntity(posTemp, sizeTemp){
			this->getShape()->setTexture("texture/ground.jpg");
			this->setID(ground);
		}

		void Ground::move(float dT){
			this->getShape()->updatePos(getPos());
		}

		void Ground::start(){
		
		}

		void Ground::collision(Entity* slamEntity, CoordF difference){	
		}
	}//final do namespace Obstacles
}//final do namespace Entities 
