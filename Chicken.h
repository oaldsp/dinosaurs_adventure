#pragma once

#include "Enemy.h"

#define C_SIZE_X  25.0f
#define C_SIZE_Y  25.0f
#define C_LIFE	  100.0f
#define C_SPEED_X 90.0f
#define C_SPEED_Y 0.0f	

namespace Creature{
	namespace Entities{

		class Chicken: public Enemy{
		private:
			float time;	
		public:
			Chicken(CoordF posTemp = CoordF(0.0f, 0.0f));
			virtual ~Chicken() = default;

			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
		};
	}//Final do namespace Entities
}//Final do namespace Creature

