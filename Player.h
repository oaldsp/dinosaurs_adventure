#pragma once

#include "Creature.h"
#include "Pcontrol.h"
#include <math.h>

#define P_SIZE_X  80.0f
#define P_SIZE_Y  50.0f
#define P_LIFE	  100.0f
#define P_SPEED_X 100.0f
#define P_SPEED_Y 80.0f

namespace Entities{
	namespace Creature{

		class Player: public Creature{
		private:
			//const bool isP1;//flag para saber se eh jogador 1
			Pcontrol ctrl;	
			float time;	
		public:
			Player(CoordF posTemp = CoordF(0.0f, 0.0f));
			virtual ~Player() = default;
			
			void damage(unsigned int damage);
			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);

			Pcontrol* getCtrl();

			void jump();
			void left();
			void right();
			void attack();
			void stop();
		};
	}//Final do namespace Creature
}//Final do namespace Entities
