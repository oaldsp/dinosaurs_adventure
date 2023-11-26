#pragma once

#include "Creature.h"
#include "Pcontrol.h"
#include "Meteor.h"
#include "Projectile.h"
#include <math.h>

#define P_SIZE_X  80.0f
#define P_SIZE_Y  50.0f
#define P_LIFE	  100.0f
#define P_SPEED_X 400.0f
#define P_SPEED_Y 300.0f
#define P_M 	  150000.0f//massa
#define PP_SIZE_X 25.0f //tamanho do projetil
#define PP_SIZE_Y 25.0f

namespace Entities{
	namespace Creature{

		class Player: public Creature{
		private:
			bool chao;//flag para saber se esta no chao
			Pcontrol ctrl;
			Projectile* prct;	
		public:
			Player(CoordF posTemp = CoordF(0.0f, 0.0f));
			~Player();
			
			void damage(const float damage);
			void move(const float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
			void repel(Entity* slamEntity);
			int getAttribute() const;

			Pcontrol* getCtrl() const;
			Projectile* getPrct() const;

			void jump();
			void left();
			void right();
			void attack();
			void stop();
		};
	}//Final do namespace Creature
}//Final do namespace Entities
