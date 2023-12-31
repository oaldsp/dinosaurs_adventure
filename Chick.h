#pragma once

#include "Enemy.h"

#define C_SIZE_X  25.0f
#define C_SIZE_Y  25.0f
#define C_LIFE	  100.0f
#define C_SPEED_Y 0.0F
#define C_SPEED_X -70.0f
#define C_M 	  50000.0f         

namespace Entities{
	namespace Creature{

		class Chick: public Enemy{
		private:
			unsigned int skill; 
		public:
			Chick(CoordF posTemp = CoordF(0.0f, 0.0f));
			virtual ~Chick() = default;

			void move(const float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
			int getAttribute() const;
		};
	}//Final do namespace Creature
}//Final do namespace Entities
