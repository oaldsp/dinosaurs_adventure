#pragma once 

#include "MoveEntity.h"

#define PR_SPEED_Y 50.0f//20
#define PR_SPEED_X 400.0f
#define PR_M	   100000.0f

namespace Entities{
	
	class Projectile: public MoveEntity{
		private:
			MoveEntity* pOwner;
			bool launched;
		public:
			Projectile(MoveEntity* pOwnerTemp);
			virtual ~Projectile();

			void move(const float dT);
			void start();
			void reset(const Entity* slamEntity);
			void collision(Entity* slamEntity, CoordF difference);
			void launch(CoordF posOwner, CoordF speedTemp);
			int getAttribute() const;
	};
}//Final do namespace Entities
