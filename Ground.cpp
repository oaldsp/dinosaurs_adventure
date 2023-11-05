#include "Ground.h"

namespace Entities{
	namespace Obstacles{
		Ground::Ground(CoordF  posTemp):
		StaticEntity(posTemp, CoordF(SIZE_X,SIZE_Y), ground)
		{
			start();
		}

		void Ground::move(float dT){
			this->getShape()->updatePos(getPos());
		}

		void Ground::start(){
			this->getShape()->setTexture("texture/ground.jpg");
		}

		void Ground::collision(Entity* slamEntity, CoordF difference){
		
		}
	}//final do namespace Obstacles
}//final do namespace Entities 