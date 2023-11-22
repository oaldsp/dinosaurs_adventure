#pragma once

#include "Coord.h"
#include "StaticAnimation.h"

#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"

enum ID{
		empty,	   //0
		chicken,   //1
		player,	   //2
		ground,	   //3
		meteor,	   //4
		coin,	   //5
		petroleum, //6
		rooster,   //7
		projectile,//8
		chick	   //9
	};

class Ente{
private:
	CoordF pos;//posicao
	CoordF speed;
	CoordF size;
	ID id;
protected:
	static Managers::GraphicsManager* pGM;
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
