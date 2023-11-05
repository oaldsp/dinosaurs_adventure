#pragma once

#include "MoveEntity.h"

namespace Entities{
	class Creature: public MoveEntity{
	private:
		unsigned int life;
		CoordF speed;
	public:
		Creature(CoordF posTemp, CoordF sizeTemp, ID idTemp , unsigned int lifeTemp, CoordF speedTemp);
		~Creature() = default;
	
		void moveAway(Entity* slamEntity, CoordF difference);
		void damage(unsigned int damage);

		//metodos virtuais puros 
		virtual void start() = 0;
		void collision(Entity* slamEntity, CoordF difference) = 0;
	};
}//final do namespace Entities
