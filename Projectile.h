#pragma once 

#include "MoveEntity.h"

#define PR_SPEED_Y 200.0f
#define PR_SPEED_X 200.0f
#define PR_M	   600000.0f

namespace Entities{
	
	class Projectile: public MoveEntity{
		private:
			MoveEntity* pOwner;
		public:
			Projectile(MoveEntity* pOwnerTemp);
			virtual ~Projectile();

			void move(const float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
			void launch(CoordF posTemp, CoordF posSpeed);
			int getAttribute() const;
	};
}//Final do namespace Entities
