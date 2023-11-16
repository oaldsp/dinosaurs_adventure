#pragma once

#include "Enemy.h"

#define CE_SIZE_X  40.0f
#define CE_SIZE_Y  40.0f
#define CE_LIFE	  100.0f
#define CE_SPEED_Y 0.0F
#define CE_SPEED_X 0.0f
#define CE_M 	  50000.0f         

namespace Entities{
	namespace Creature{

		class Chicken: public Enemy{
		private:
			float cooldown; 
		public:
			Chicken(CoordF posTemp = CoordF(0.0f, 0.0f));
			virtual ~Chicken() = default;

			void move(const float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
			int getAttribute() const;
		};
	}//Final do namespace Creature
}//Final do namespace Entities

