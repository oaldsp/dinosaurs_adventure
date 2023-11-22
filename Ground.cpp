#include "Ground.h"

namespace Entities{
	namespace Obstacles{
		Ground::Ground(CoordF  posTemp, CoordF sizeTemp):
		Obstacle(posTemp, sizeTemp){
			srand(std::time(NULL));
			friction= rand()%3 + 1;
			start();
		}

		void Ground::move(const float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();

			float a = getG() - getN();
						
			setTime(getTime() + dT);
				
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() + a*getTime()*getTime()/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
		}

		void Ground::start(){
			this->getShape()->setTexture("texture/ground.jpg");
			this->setSpeedX(0.0f);
			this->setSpeedY(0.0f);
			this->setID(ground);
		}

		void Ground::collision(Entity* slamEntity, CoordF difference){	
		}

		int Ground::getAttribute() const{
			return friction;	
		}
	}//final do namespace Obstacles
}//final do namespace Entities 
