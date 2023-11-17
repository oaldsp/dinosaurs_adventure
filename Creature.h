#pragma once

#include "MoveEntity.h"

using namespace Entities;

namespace Entities{ 
	namespace Creature{

		class Creature: public MoveEntity{
		private:
			float life;
		public:
			Creature(CoordF posTemp, CoordF sizeTemp);
			~Creature() = default;
		
			void moveAway(Entity* slamEntity, CoordF difference);
			
			float getLife() const;
			void setLife(const float lifeTemp);
		
			//metodos virtuais puros
			virtual void move(const float dT) = 0; 
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
			virtual int getAttribute() const=  0;
		};
	}//final do namespace Creature
}//Final do namespace Entities
