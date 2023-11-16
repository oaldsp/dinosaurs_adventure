#include "Rooster.h"

namespace Entities{
	namespace Creature{

		Rooster::Rooster(CoordF  posTemp):
		Enemy(posTemp, CoordF(R_SIZE_X, R_SIZE_Y)),
		protect(0){
			start();
		}

		void Rooster::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();

			float a = getG() - (getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*R_M);
			/*
				Formula da aceleracao considerando arasto
					a = g - (K*x^2*v^2) /2m
			 */
			
			setTime(getTime() + dT);	
			
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() + a*getTime()*getTime()/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
			
			this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
		}

		void Rooster::start(){
			this->getShape()->setTexture("texture/rooster.png");
			this->setID(rooster);
			this->setLife(R_LIFE);
			this->setSpeedX(R_SPEED_X);
		}

		void Rooster::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case ground:
				setTime(0.0f);//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			case chicken:
				setSpeedX(2.5f*R_SPEED_X);
				protect = true;
				break;
			case petroleum:
				setTime(0.0f);//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			default:
				break;
			}	
		}

		int Rooster::getAttribute() const{
			return (int)protect;
		}
	}//Final do namespace Creature
}//Final do namespace Entities


