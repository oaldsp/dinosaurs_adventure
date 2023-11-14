#pragma once

#include "Obstacle.h"

#define M_SIZE_X  30.0f
#define M_SIZE_Y  30.0f
#define M_SPEED_X 0.0f
#define M_SPEED_Y 0.0f
#define M_M 	  4000.0f//massa

namespace Entities{
	namespace Obstacles{ 

		class Meteor: public Obstacle{
		private:
			float time;
			int riskLevel;
		public:
			Meteor(CoordF posTemp = CoordF(0.0f,0.0f));
			~Meteor() = default;

			int getRisk() const;

			//metodos virtuais puros
			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
		};
	}//final do namespace Obstacles
}//final do namespace Entity

