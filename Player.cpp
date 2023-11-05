#include "Player.h"

namespace Creature{
	namespace Entities{

		Player::Player(CoordF  posTemp, bool isP1Temp):
		Creature(posTemp, CoordF(P_SIZE_X,P_SIZE_Y), player, P_LIFE, CoordF(P_SPEED_X,P_SPEED_Y)),
		isP1(isP1Temp){
			start();
			time=0;
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
			time += dT;
			this->getShape()->updatePos(posTemp);
			if(time < 10.0f)
				this->setPos(CoordF(posTemp.x +  P_SPEED_X*dT, posTemp.y + P_SPEED_Y*dT));
			else if (time < 20.0f)
				this->setPos(CoordF(posTemp.x -  P_SPEED_X*dT, posTemp.y + P_SPEED_Y*dT));
			else	
				time = 0;
			
		}

		void Player::start(){
			this->getShape()->setTexture("texture/player.png");
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
	}//Final do namespace Entities
}//Final do namespace Creature
