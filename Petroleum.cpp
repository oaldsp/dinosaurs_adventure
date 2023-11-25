#include "Petroleum.h"

namespace Entities{
	namespace Obstacles{
		Petroleum::Petroleum(CoordF  posTemp, CoordF sizeTemp):
		Obstacle(posTemp, sizeTemp){
			srand(std::time(NULL));
			viscosity = rand()%11 + 10;
			start();
		}

		void Petroleum::move(const float dT){
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

		void Petroleum::start(){
			this->getShape()->setTexture("texture/petroleum.jpg");
			this->setSpeedX(0.0f);
			this->setSpeedY(0.0f);
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

