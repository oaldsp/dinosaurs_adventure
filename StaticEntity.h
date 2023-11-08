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

		//metodos virtuais puros 
		virtual void start() = 0;
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
	};
}//Final do namespace Entities
