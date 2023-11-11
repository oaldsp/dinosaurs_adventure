#pragma once

#include "Creature.h"

namespace Entities{
	namespace Creature{

		class Enemy: public Creature{
		private:
			float time;	
		public:
			Enemy(CoordF posTemp = CoordF(0.0f, 0.0f), CoordF sizeTemp = CoordF(0.0f, 0.0f)); 
				
			virtual ~Enemy() = default;

			virtual void move(float dT) = 0;
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		};
	}//Final do namespace Creature
}//Final do namespace Entities

