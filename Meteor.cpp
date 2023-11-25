#include "Meteor.h"

namespace Entities{
	namespace Obstacles{
		Meteor::Meteor(CoordF  posTemp):
		Obstacle(posTemp, CoordF(M_SIZE_X, M_SIZE_Y)){
			srand(std::time(NULL));
			riskLevel = rand()%4 +1;
			start();
		}
		
		void Meteor::move(const float dT){
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

		void Meteor::start(){
			this->getShape()->setTexture("texture/meteor.png");
			this->setSpeedX(0.0f);
			this->setSpeedY(0.0f);
			this->setID(meteor);
		}

		void Meteor::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){
			default:
				break;
			}
		}

		int Meteor::getAttribute() const{
			return riskLevel;
		}
	}//final do namespace Obstacles
}//final do namespace Entities 

