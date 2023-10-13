#pragma once

#include "player.h"

Player::Player(CoordF  posTemp, bool isP1Temp):
Entity(posTemp, CoordF(P_SIZE_X,P_SIZE_Y), player), 
isP1(isP1Temp){

}

Player::~Player(){}

void Player::plot(){}

void Player::move(float temp){}

void Player::start(){
	exit(1);
}
