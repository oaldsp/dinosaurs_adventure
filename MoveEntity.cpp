#include "MoveEntity.h"

namespace Entities{

	MoveEntity::MoveEntity(CoordF posTemp, CoordF sizeTemp):
	Entity(posTemp), live(true), time(0),
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
	
	float MoveEntity::getTime() const{
		return time;
	}

	void MoveEntity::setTime(const float timeTemp){
		time=timeTemp;
	}

	StaticAnimation* MoveEntity::getShape(){
		return &shape;
	}
}//Final do namespace Entities
