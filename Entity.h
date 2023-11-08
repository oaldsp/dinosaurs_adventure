#pragma once 

#include "Coord.h"
#include "StaticAnimation.h"

namespace Entities{

	enum ID{
		empty,
		chicken,
		player,
		ground,
		coin
	};

	class Entity{
	private:
		CoordF pos;//posicao
		CoordF size;
		ID id;
	public:
		Entity(CoordF posTemp = CoordF(0.f, 0.f));

		~Entity();
		
		//set's
		void setPos(CoordF posTemp);
		void setSize(CoordF sizeTemp);
		void setID(ID idTemp);
		
		//get's
		CoordF getSize() const;
		CoordF getPos() const;
		ID getID() const;

		//metodos virtuais
		virtual void plot() = 0;//plotar entity na tela
		virtual void move(float dT) = 0;//mover entity
		virtual void start() = 0;//inicializar entity
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
	};
}//final donamespace Entities
