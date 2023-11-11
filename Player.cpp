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
		
		}

		void Player::start(){
			this->getShape()->setTexture("texture/player.png");
			this->setID(player);
			this->setLife(P_LIFE);
			this->setSpeedX(P_SPEED_X);
			time=0;
		}

		void Player::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case chicken:
				this->damage(101);
				break;
			case ground:
				this->moveAway(slamEntity, difference);
				break;
			default:
				break;
			}	
		}

		void Player::jump(){
			
		}

		void Player::left(){
			this->setPos(CoordF(getPos().x - getSpeed().x, getPos().y));
		}

		void Player::right(){
			this->setPos(CoordF(getPos().x + getSpeed().x, getPos().y));
		}

		void Player::attack(){
		
		}

	}//Final do namespace Creature 
}//Final do namespace Entities
