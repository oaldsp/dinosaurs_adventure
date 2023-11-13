#include "Entity.h"

namespace Entities{

	const float Entity::gravity = G;
	const float Entity::cte = K;

	Entity::Entity(CoordF posTemp):speed(CoordF(0.0f, 0.0f)){
		pos  = posTemp;
	}

	Entity::~Entity(){

	}

	void Entity::setPos(CoordF posTemp){
		pos=posTemp;
	}

	void Entity::setSize(CoordF sizeTemp){
		size=sizeTemp;
	}

	void Entity::setID(ID idTemp){
		id=idTemp;
	}
	
	void Entity::setSpeedX(float xTemp){
		speed.x = xTemp;
	}	
		
	void Entity::setSpeedY(float yTemp){
		speed.y = yTemp;
	}
	
	float Entity::getG(){
		return gravity;
	}
	
	float Entity::getK(){
		return cte;
	}

	CoordF Entity::getSize() const{
		return size;
	}

	CoordF Entity::getPos() const{
		return pos;
	}

	ID Entity::getID() const{
		return id;
	}
	
	CoordF Entity::getSpeed() const{
		return speed; 
	}
}//final do namespace Entities
