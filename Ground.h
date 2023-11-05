#pragma once

#include "StaticEntity.h"

#define SIZE_X 500.0f
#define SIZE_Y 100.0f

namespace Entities{
	namespace Obstacles{ 

		class Ground: public StaticEntity{
		private:
		public:
			Ground(CoordF posTemp = CoordF(0.0f,0.0f));
			~Ground() = default;

			//metodos virtuais puros
			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
		};
	}//final do namespace Obstacles
}//final do namespace Entity
