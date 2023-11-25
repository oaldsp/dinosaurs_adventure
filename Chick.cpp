#include "Chick.h"

namespace Entities{
	namespace Creature{

		Chick::Chick(CoordF  posTemp):
		Enemy(posTemp, CoordF(C_SIZE_X, C_SIZE_Y)){
			srand(std::time(NULL));
			skill = rand()%3 +1;
			start();
		}

		void Chick::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();
		
			float a = getG() - (getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*C_M);
			/*
				Formula da aceleracao considerando arasto
					a = g - (K*x^2*v^2) /2m
			 */
			
			this->setTime(getTime() + dT);	
				
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() + a*getTime()*getTime()/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
			
			this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
		}

		void Chick::start(){
			this->getShape()->setTexture("texture/chick.png");
			this->setID(chick);
			this->setLife(C_LIFE);
			this->setSpeedX(C_SPEED_X);
		}

		void Chick::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case ground:
				if(difference.x >= difference.y)
					setSpeedX(-getSpeed().x);
				setTime(0.0f);//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			case petroleum:
				if((difference.x >= difference.y) && rand()%2)
					setSpeedX(-getSpeed().x);
				setTime(0.0f);//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			case player:
				this->damage(100.0f);
				break;
			case projectile:
				this->damage(100.0f);
				break;
			default:
				break;
			}	
		}

		int Chick::getAttribute() const{
			return skill;
		}
	}//Final do namespace Creature
}//Final do namespace Entities

