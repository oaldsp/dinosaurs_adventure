#include "Meteor.h"

namespace Entities{
	namespace Obstacles{
		Meteor::Meteor(CoordF  posTemp, CoordF sizeTemp):
		StaticEntity(posTemp, sizeTemp){
			start();
		}

		void Meteor::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();

			float a = getG()  - (getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*M_M);
			/*
				Formula da aceleracao considerando arasto
					a = g - (K*x^2*v^2) /2m
			 */
				
			time += dT;
				
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*time + a*time*time/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
			
			this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
		}

		void Meteor::start(){
			this->getShape()->setTexture("texture/meteor.png");
			this->setID(ground);
		}

		void Meteor::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){
			case ground:
				printf("bateu");
				time = 0.0f;//zero o tempo para o jump
				setSpeedY(0.0f);	
				break;
			default:
				break;
			}
		}
	}//final do namespace Obstacles
}//final do namespace Entities 

