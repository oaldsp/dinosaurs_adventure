#include "Obstacle.h"

namespace Entities::Obstacles{
	
	unsigned int Obstacle::obstacleTotal = 0;
	const float Obstacle::normal = getG();

	Obstacle::Obstacle(CoordF posTemp, CoordF sizeTemp):StaticEntity(posTemp, sizeTemp){
		obstacleTotal++;
	}

	Obstacle::~Obstacle(){
		obstacleTotal--;
	}

	float Obstacle::getN(){
		return normal;
	}
}//Final do namespace Entities::Obstacle
