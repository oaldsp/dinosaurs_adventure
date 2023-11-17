#pragma once

#include "Obstacle.h"

namespace Entities{
	namespace Obstacles{ 

		class Petroleum: public Obstacle{
		private:
			int viscosity;
		public:
			Petroleum(CoordF posTemp = CoordF(0.0f,0.0f), CoordF sizeTemp = CoordF(0.0f,0.0f));
			~Petroleum() = default;

			//metodos virtuais puros
			void move(const float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
			int getAttribute() const;
		};
	}//final do namespace Obstacles
}//final do namespace Entity

