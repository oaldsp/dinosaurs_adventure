#pragma once

#include "StaticEntity.h"

namespace Entities::Obstacles{

	class Obstacle: public StaticEntity{
	private:
	
	public:
		Obstacle(CoordF posTemp, CoordF sizeTemp);
		~Obstacle() = default;
		
		//metodos virtuais puros
		virtual void move(float dT) = 0; 
		virtual void start() = 0;
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
	};
}//Final do namespace Entities::Obstacles
