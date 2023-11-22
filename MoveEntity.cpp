#include "MoveEntity.h"

namespace Entities{

	MoveEntity::MoveEntity(CoordF posTemp, CoordF sizeTemp):
	Entity(posTemp), live(true),
	shape(posTemp, sizeTemp){
		this->setSize(sizeTemp);
	}

	void MoveEntity::plot(){
		shape.plot();		
	}
	
	bool MoveEntity::getLive(){
		return live;
	}

	void MoveEntity::setLive(bool temp){
		live = temp;
	}
	
	StaticAnimation* MoveEntity::getShape(){
		return &shape;
	}
}//Final do namespace Entities
