#pragma once

#include "StaticEntity.h"

#define M_SIZE_X  80.0f
#define M_SIZE_Y  50.0f
#define M_SPEED_X 0.0f
#define M_SPEED_Y 0.0f
#define M_M 	  4000.0f//massa

namespace Entities{
	namespace Obstacles{ 

		class Meteor: public StaticEntity{
		private:
			float time;
		public:
			Meteor(CoordF posTemp = CoordF(0.0f,0.0f), CoordF sizeTemp = CoordF(0.0f,0.0f));
			~Meteor() = default;

			//metodos virtuais puros
			void move(float dT);
			void start();
			void collision(Entity* slamEntity, CoordF difference);
		};
	}//final do namespace Obstacles
}//final do namespace Entity

