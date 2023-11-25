#pragma once

#include "Creature.h"

namespace Entities{
	namespace Creature{

		class Enemy: public Creature{
		private:
			static unsigned int enemyTotal;
		public:
			Enemy(CoordF posTemp = CoordF(0.0f, 0.0f), CoordF sizeTemp = CoordF(0.0f, 0.0f)); 
				
			virtual ~Enemy();

			void damage(const float damage);

			virtual void move(const float dT) = 0;
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
			virtual int getAttribute() const=  0;
		};
	}//Final do namespace Creature
}//Final do namespace Entities

