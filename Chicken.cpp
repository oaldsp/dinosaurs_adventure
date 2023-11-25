#include "Chicken.h"

namespace Entities{
	namespace Creature{

		Chicken::Chicken(CoordF  posTemp, Projectile*  prctTemp):
		Enemy(posTemp, CoordF(CE_SIZE_X, CE_SIZE_Y)), 
		cooldown(CE_CW), prct(prctTemp){	
			start();	
		}

		Chicken::~Chicken(){
			prct  = NULL;
		}

		void Chicken::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();
		
			float a = getG() - (getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*CE_M);
			/*
				Formula da aceleracao considerando arasto
					a = g - (K*x^2*v^2) /2m
			 */
			
			this->setTime(getTime() + dT);	
			cooldown -= dT;

			this->attack();

			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() + a*getTime()*getTime()/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
			
			this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
		}

		void Chicken::start(){
			prct = new Projectile(this);
			this->getShape()->setTexture("texture/chicken.png");
			prct->getShape()->setTexture("texture/prctE.png");
			prct->getShape()->changeSize(CoordF(PE_SIZE_X, PE_SIZE_Y));//Muda no StaticAnimation
			prct->setSize(CoordF(PE_SIZE_X, PE_SIZE_Y));//Muda no Ente
			this->setID(chicken);
			this->setLife(CE_LIFE);
			this->setSpeedX(CE_SPEED_X);
		}
		
		void Chicken::attack(){
			if(cooldown <= 0.0f){
				/*VER PORQUE AO COLOCAR ESSES CARAS NO START DA "SEGFOU"*/
				prct->getShape()->setTexture("texture/prctE.png");
				prct->getShape()->changeSize(CoordF(PE_SIZE_X, PE_SIZE_Y));//Muda no StaticAnimation
				prct->setSize(CoordF(PE_SIZE_X, PE_SIZE_Y));//Muda no Ente
				prct->launch(this->getPos(), this->getSpeed());
				cooldown = CE_CW;
			}
		}

		void Chicken::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case ground:
				setTime(0.0f);//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			case petroleum:
				setTime(0.0f);//zero o tempo para o jump
				moveAway(slamEntity,difference);
				break;
			case player:
				this->damage(100.0f);
				break;
			case projectile:
				if(slamEntity != prct)
					this->damage(100.0f);
				break;
			default:
				break;
			}	
		}

		int Chicken::getAttribute() const{
			return 1;
		}
	}//Final do namespace Creature
}//Final do namespace Entities


