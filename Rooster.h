#pragma once

#include "Enemy.h"

#define R_SIZE_X  60.0f
#define R_SIZE_Y  60.0f
#define R_LIFE	  300.0f
#define R_SPEED_Y 50.0F
#define R_SPEED_X 100.0f
#define R_M 	  50000.0f         

namespace Entities{
	namespace Creature{

		class Rooster: public Enemy{
		private:
			float time;
			bool protect; 
		public:
			Rooster(CoordF posTemp = CoordF(0.0f, 0.0f));
			virtual ~Rooster() = default;

			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
		};
	}//Final do namespace Creature
}//Final do namespace Entities
