#include "Player.h"

namespace Entities{
	namespace Creature{
		
		Player::Player(CoordF  posTemp):
		Creature(posTemp, CoordF(P_SIZE_X,P_SIZE_Y)),
		ctrl(this),
		chao(true){			
			start();		
		}

		void Player::damage(unsigned int damage){
			int life = this->getLife();
			life-=damage;
			if(life <= 0){
				cout << "VOCE PERDEU" << endl;
				exit(1);
			}	
		}
		
		void Player::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();

			float a = getG() - (getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*P_M);
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

		void Player::start(){
			this->getShape()->setTexture("texture/player.png");
			this->setID(player);
			this->setLife(P_LIFE);
			this->setSpeedX(0.0f);
			time=0;
		}

		void Player::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case chicken:
				this->damage(101);
				break;
			case rooster:
				this->damage(101);
				break;
			case ground:
				chao = true;
				time = 0.0f;//zero o tempo para o jump
				this->moveAway(slamEntity, difference);
				break;
			case petroleum:
				chao = false;
				time = 0.0f;//zero o tempo para o jump
				this->moveAway(slamEntity, difference);
				break;
			case meteor:
				this->damage(25);
				setSpeedX(-3.0f*getSpeed().x);
				setSpeedY(-1.5f*getSpeed().y);
				break;
			default:
				break;
			}	
		}

		Pcontrol* Player::getCtrl(){
			return &ctrl;
		}

		void Player::jump(){
			if(chao){       	
				this->setPos(CoordF(getPos().x, getPos().y - 10.0f));
				this->setSpeedY(-P_SPEED_Y);
			}
			chao = false;
		}

		void Player::left(){
			this->setSpeedX(-P_SPEED_X);
		}

		void Player::right(){
			this->setSpeedX(P_SPEED_X);
		}

		void Player::attack(){
			
		}

		void Player::stop(){
			this->setSpeedX(0.0f);
		}

	}//Final do namespace Creature 
}//Final do namespace Entities
