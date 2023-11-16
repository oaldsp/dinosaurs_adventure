#pragma once

#include "Coord.h"
#include "StaticAnimation.h"

enum ID{
		empty,
		chicken,
		player,
		ground,
		meteor,
		coin,
		petroleum,
		rooster,
		projectile,
		chick
	};

class Ente{
private:
	CoordF pos;//posicao
	CoordF speed;
	CoordF size;
	ID id;
public:
	Ente(CoordF posTemp);
	~Ente() = default;

	//set's
	void setPos(CoordF posTemp);
	void setSize(CoordF sizeTemp);
	void setID(ID idTemp);
	void setSpeedX(const float xTemp);
	void setSpeedY(const float yTemp);

	//get's
	CoordF getSize() const;
	CoordF getPos() const;
	ID getID() const;
	CoordF getSpeed() const;

	//metodos virtuais
	virtual void plot() = 0;//plotar entity na tela
	virtual void move(const float dT) = 0;//mover entity
	virtual void start() = 0;//inicializar entity
};
