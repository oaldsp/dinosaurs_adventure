#pragma once

#include "Creature.h"

namespace Creature{
	namespace Entities{

		class Enemy: public Creature{
		private:
			float time;	
		public:
			Enemy(CoordF posTemp = CoordF(0.0f, 0.0f), 
			CoordF sizeTemp = CoordF(0.0f, 0.0f), 
			ID idTemp = empty, 
			unsigned int lifeTemp = 100.0f, 
			CoordF speedTemp = CoordF(0.0f, 0.0f));
			
			virtual ~Enemy() = default;

			virtual void move(float dT) = 0;
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		};
	}//Final do namespace Entities
}//Final do namespace Creature

