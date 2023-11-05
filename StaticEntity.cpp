#include "StaticEntity.h"

namespace Entities{

	StaticEntity::StaticEntity(CoordF posTemp, CoordF sizeTemp , ID idTemp):
	Entity(posTemp, sizeTemp, empty),
	shape(posTemp, sizeTemp, 1.0f){}

	void StaticEntity::plot(){
		shape.plot();
	}

	StaticAnimation StaticEntity::getShape(){
		return shape;
	}
}//Final do namespace Entities
