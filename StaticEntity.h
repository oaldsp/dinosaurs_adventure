#pragma once

#include "Entity.h"
#include  "StaticAnimation.h"

namespace Entities{

	class StaticEntity:public Entity{
	private:
		StaticAnimation shape;
	public:
		StaticEntity(CoordF posTemp, CoordF sizeTemp);
		~StaticEntity() =  default;

		void plot();
		StaticAnimation* getShape();

		//metodos virtuais puro
		virtual void move(const float dT) = 0; 
		virtual void start() = 0;
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		virtual int getAttribute() const = 0;
	};
}//Final do namespace Entities
