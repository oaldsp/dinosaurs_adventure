#pragma once 

#include "Coord.h"
#include "StaticAnimation.h"

enum ID{
	empty,
	player,
	platform
};

class Entity{
private:
	CoordF pos;//posicao
	CoordF size;
	ID id;
public:
	Entity(CoordF posTemp = CoordF(0.f, 0.f), CoordF sizeTemp = CoordF(0.f, 0.f), ID idTemp = empty);

	~Entity();
	
	//set's
	void setPos(CoordF temp);
	
	//get's
	CoordF getSize() const;
	CoordF getPos() const;
	ID getID() const;

	//metodos virtuais
	virtual void plot() = 0;//plotar entity na tela
	virtual void move(float temp) = 0;//mover entity
	virtual void start() = 0;//inicializar entity
}; 
	
