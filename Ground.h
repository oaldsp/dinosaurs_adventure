#pragma once

#include "Obstacle.h"

namespace Entities{
	namespace Obstacles{ 

		class Ground: public Obstacle{
		private:
			int friction;
		public:
			Ground(CoordF posTemp = CoordF(0.0f,0.0f), CoordF sizeTemp = CoordF(0.0f,0.0f));
			~Ground() = default;

			//metodos virtuais puros
			void move(const float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
			int getAttribute() const;
		};
	}//final do namespace Obstacles
}//final do namespace Entity
