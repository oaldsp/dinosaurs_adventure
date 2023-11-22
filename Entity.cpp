#include "Entity.h"

namespace Entities{

	const float Entity::gravity = G;
	const float Entity::cte = K;

	Entity::Entity(CoordF posTemp):Ente(posTemp), time(0.0f){}
		
	float Entity::getG(){
		return gravity;
	}
	
	float Entity::getK(){
		return cte;
	}

	float Entity::getTime() const{
		return time;
	}

	void Entity::setTime(const float timeTemp){
		time=timeTemp;
	}
}//final do namespace Entities
