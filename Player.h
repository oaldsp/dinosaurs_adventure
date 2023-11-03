#pragma once

#include "Entity.h"

#define P_SIZE_X 100.0f
#define P_SIZE_Y 100.0f

class Player: public Entity{
private:
	const bool isP1;//flag para saber se eh jogador 1
 	float time;
	StaticAnimation shape;	
public:
	Player(CoordF posTemp = CoordF(0.0f, 0.0f), bool isP1Temp = true);
	virtual ~Player() = default;

	//metodos virtuais
	void plot();
	void move(float dT);
	void start();
};
