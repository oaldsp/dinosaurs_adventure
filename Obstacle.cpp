#include "Obstacle.h"

namespace Entities::Obstacles{
	
	unsigned int Obstacle::ObstacleTotal = 0;

	Obstacle::Obstacle(CoordF posTemp, CoordF sizeTemp):StaticEntity(posTemp, sizeTemp){
		ObstacleTotal++;
	}
}//Final do namespace Entities::Obstacle
