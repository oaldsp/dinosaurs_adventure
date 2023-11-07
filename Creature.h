#pragma once

#include "MoveEntity.h"

using namespace Entities;

namespace Creature{ 
	namespace Entities{

		class Creature: public MoveEntity{
		private:
			unsigned int life;
			CoordF speed;
		public:
			Creature(CoordF posTemp, CoordF sizeTemp, ID idTemp , unsigned int lifeTemp, CoordF speedTemp);
			~Creature() = default;
		
			void moveAway(Entity* slamEntity, CoordF difference);
			void damage(unsigned int damage);
			unsigned int getLife() const;

			//metodos virtuais puros
			virtual void move(float dT) = 0; 
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		};
	}//final do namespace Entities
}//Final do namespace Creature
