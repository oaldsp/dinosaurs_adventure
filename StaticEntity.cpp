#include "StaticEntity.h"

namespace Entities{

	StaticEntity::StaticEntity(CoordF posTemp, CoordF sizeTemp):
	Entity(posTemp),
	shape(posTemp, sizeTemp){}

	void StaticEntity::plot(){
		shape.plot();
	}

	StaticAnimation* StaticEntity::getShape(){
		return &shape;
	}
}//Final do namespace Entities
