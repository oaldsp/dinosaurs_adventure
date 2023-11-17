#pragma once 

#include "Ente.h"

#define G 100.0f//gravidade
#define K 10.0f //C*p*pi
// C -> coeficiente de arrasto
// p -> densidade do fluido 

namespace Entities{

	class Entity: public Ente{
	private:
		static const float gravity;
		static const float cte;
	public:
		Entity(CoordF posTemp = CoordF(0.f, 0.f));

		~Entity() = default;
		
		//get's
		static float getG();
	       	static float getK();

		//metodos virtuais
		virtual void plot() = 0;//plotar entity na tela
		virtual void move(const float dT) = 0;//mover entity
		virtual void start() = 0;//inicializar entity
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		virtual int getAttribute() const =  0;
	};
}//final donamespace Entities
