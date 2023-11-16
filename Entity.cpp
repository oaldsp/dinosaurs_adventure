#include "Entity.h"

namespace Entities{

	const float Entity::gravity = G;
	const float Entity::cte = K;

	Entity::Entity(CoordF posTemp):Ente(posTemp){}
		
	float Entity::getG(){
		return gravity;
	}
	
	float Entity::getK(){
		return cte;
	}
}//final do namespace Entities
