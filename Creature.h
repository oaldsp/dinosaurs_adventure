#pragma once

#include "MoveEntity.h"

#define G -0.0f

using namespace Entities;

namespace Creature{ 
	namespace Entities{

		class Creature: public MoveEntity{
		private:
			unsigned int life;
			CoordF speed;
		public:
			Creature(CoordF posTemp, CoordF sizeTemp);
			~Creature() = default;
		
			void moveAway(Entity* slamEntity, CoordF difference);
			void damage(unsigned int damage);
			unsigned int getLife() const;
			
			void setLife(unsigned int lifeTemp);
			void setSpeedX(float xTemp);
			void setSpeedY(float yTemp);

			//metodos virtuais puros
			virtual void move(float dT) = 0; 
			virtual void start() = 0;
			virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		};
	}//final do namespace Entities
}//Final do namespace Creature
