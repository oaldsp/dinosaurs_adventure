#pragma once

#include "MoveEntity.h"

using namespace Entities;

namespace Entities{ 
	namespace Creature{

		class Creature: public MoveEntity{
		private:
			unsigned int life;
		public:
			Creature(CoordF posTemp, CoordF sizeTemp);
			~Creature() = default;
		
			void moveAway(Entity* slamEntity, CoordF difference);
			void damage(unsigned int damage);
			unsigned int getLife() const;
			
			void setLife(unsigned int lifeTemp);
			
			//metodos virtuais puros
			virtual void move(float dT) = 0; 
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		};
	}//final do namespace Creature
}//Final do namespace Entities
