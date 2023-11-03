#include "Entity.h"

Entity::Entity(CoordF posTemp, CoordF sizeTemp, ID idTemp){
	pos  = posTemp;
	size = sizeTemp;
	id = idTemp;
}

Entity::~Entity(){

}

void Entity::setPos(CoordF temp){
	pos=temp;
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
