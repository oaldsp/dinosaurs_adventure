#include "Chicken.h"

namespace Entities{
	namespace Creature{

		Chicken::Chicken(CoordF  posTemp):
		Enemy(posTemp, CoordF(C_SIZE_X, C_SIZE_Y)){
			srand(std::time(NULL));
			skill = rand()%3 +1;
			start();
		}

		void Chicken::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();

			float a = getG() - (getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*C_M);
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

		void Chicken::start(){
			this->getShape()->setTexture("texture/chicken.png");
			this->setID(chicken);
			this->setLife(C_LIFE);
			this->setSpeedX(C_SPEED_X);
			time=0;
		}

		void Chicken::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case ground:
				time = 0.0f;//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			default:
				break;
			}	
		}
	}//Final do namespace Creature
}//Final do namespace Entities

