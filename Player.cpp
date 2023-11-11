#include "Player.h"

namespace Entities{
	namespace Creature{

		Player::Player(CoordF  posTemp):
		Creature(posTemp, CoordF(P_SIZE_X,P_SIZE_Y)),
		ctrl(this)
		/*,isP1(true)*/{			
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
			
			time += dT;
			
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*time + G*time*time/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
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
			case ground:
				time = 0.0f;//zero o tempo para o jump
				this->moveAway(slamEntity, difference);
				break;
			default:
				break;
			}	
		}

		Pcontrol* Player::getCtrl(){
			return &ctrl;
		}

		void Player::jump(){
			this->setPos(CoordF(getPos().x, getPos().y - 10.0f));
			this->setSpeedY(-P_SPEED_Y);
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
