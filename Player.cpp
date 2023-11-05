#include "Player.h"

namespace Entities{

	Player::Player(CoordF  posTemp, bool isP1Temp):
	Creature(posTemp, CoordF(P_SIZE_X,P_SIZE_Y), player, LIFE, CoordF(P_SPEED_X,P_SPEED_Y)),
	isP1(isP1Temp){
		start();
		time=0;
	}

	void Player::move(float dT){
		CoordF posTemp = this->getPos();
		time += dT;
		this->getShape().updatePos(posTemp);
			this->setPos(CoordF(posTemp.x +  200*dT, posTemp.y));
	}

	void Player::start(){
		//(((MoveEntity*)this)->getShape()).setTexture("texture/player.png");
	}

	void Player::collision(Entity* slamEntity, CoordF difference){
		switch(slamEntity->getID()){ 
		case ground:
			moveAway(slamEntity,difference);
			break;
		default:
			break;
		}	
	}
}//Final no namespace Entities
