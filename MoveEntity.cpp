#include "MoveEntity.h"

namespace Entities{

	MoveEntity::MoveEntity(CoordF posTemp, CoordF sizeTemp, ID idTemp):
	Entity(posTemp, sizeTemp, empty), live(true),
	shape(posTemp, sizeTemp, 1.0f){}

	void MoveEntity::plot(){
		shape.plot();		
	}
	
	bool MoveEntity::getLive(){
		return live;
	}

	void MoveEntity::setLive(bool temp){
		live = temp;
	}
		
	StaticAnimation MoveEntity::getShape(){
		printf("1");
		return shape;
	}
}//Final do namespace Entities
