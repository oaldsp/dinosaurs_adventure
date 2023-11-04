#include "Player.h"

Player::Player(CoordF  posTemp, bool isP1Temp):
Entity(posTemp, CoordF(P_SIZE_X,P_SIZE_Y), player),
shape("texture/player.png", posTemp, CoordF(100,100) ,1),	
isP1(isP1Temp){
	start();
	time=0;
}

void Player::plot(){
	shape.plot();
}

void Player::move(float dT){
	time += dT;
	shape.updatePos(getPos());
	setPos(CoordF(getPos().x +  200*dT,getPos().y));
}

void Player::start(){
	//shape("texture/player.png", posTemp, CoordF(100,100) ,1);
}
