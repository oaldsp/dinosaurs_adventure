#include "Entity.h"

namespace Entities{

	Entity::Entity(CoordF posTemp){
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

	CoordF Entity::getSize() const{
		return size;
	}

	CoordF Entity::getPos() const{
		return pos;
	}

	ID Entity::getID() const{
		return id;
	}
}//final do namespace Entities
