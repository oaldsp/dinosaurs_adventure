#pragma once

#include "Creature.h"

#define P_SIZE_X  80.0f
#define P_SIZE_Y  50.0f
#define P_LIFE	  100.0f
#define P_SPEED_X 50.0f
#define P_SPEED_Y 40.0f	

namespace Creature{
	namespace Entities{

		class Player: public Creature{
		private:
			const bool isP1;//flag para saber se eh jogador 1
			float time;	
		public:
			Player(CoordF posTemp = CoordF(0.0f, 0.0f), bool isP1Temp = true);
			virtual ~Player() = default;
			
			void damage(unsigned int damage);
			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
		};
	}//Final do namespace Entities
}//Final do namespace Creature
