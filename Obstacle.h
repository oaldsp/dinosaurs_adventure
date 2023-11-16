#pragma once

#include "StaticEntity.h"

namespace Entities::Obstacles{

	class Obstacle: public StaticEntity{
	private:
		static unsigned int ObstacleTotal;	
	public:
		Obstacle(CoordF posTemp, CoordF sizeTemp);
		~Obstacle() = default;
		
		//metodos virtuais puros
		virtual void move(const float dT) = 0; 
		virtual void start() = 0;
		virtual void collision(Entity* slamEntity, CoordF difference) = 0;
		virtual int getAttribute() const =  0;
	};
}//Final do namespace Entities::Obstacles
