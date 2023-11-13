#pragma once 

#include "Coord.h"
#include "StaticAnimation.h"

#define G 100.0f//gravidade
#define K 10.0f //C*p*pi
// C -> coeficiente de arrasto
// p -> densidade do fluido 

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
		CoordF speed;
		CoordF size;
		static const float gravity;
		static const float cte;
		ID id;
	public:
		Entity(CoordF posTemp = CoordF(0.f, 0.f));

		~Entity();
		
		//set's
		void setPos(CoordF posTemp);
		void setSize(CoordF sizeTemp);
		void setID(ID idTemp);
		void setSpeedX(float xTemp);
		void setSpeedY(float yTemp);
		
		//get's
		static float getG();
	       	static float getK(); 	
		CoordF getSize() const;
		CoordF getPos() const;
		ID getID() const;
		CoordF getSpeed() const;

		//metodos virtuais
		virtual void plot() = 0;//plotar entity na tela
		virtual void move(float dT) = 0;//mover entity
		virtual void start() = 0;//inicializar entity
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
	};
}//final donamespace Entities
