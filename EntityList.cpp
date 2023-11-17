#include "EntityList.h"

namespace List{

	EntityList::~EntityList(){
		list.clear();
	}

	void EntityList::addEntity(Entity* pTemp){
		list.push(pTemp); 
	}

	void EntityList::removeEntity(Entity* pTemp){
		list.pop(pTemp);
	}

	void EntityList::removeEntity(unsigned int pos){
		list.pop(pos);
	}

	void EntityList::plot(){
		list.setActual(list.getFirst());
		list.getActual()->getData()->plot();

		while(list.getActual() != list.getLast()){
			list.setActual(list.getActual()->getNext());
			list.getActual()->getData()->plot(); 
		}
	}
	
	void EntityList::move(const float dT){
		list.setActual(list.getFirst());
		list.getActual()->getData()->move(dT);

		while(list.getActual() != list.getLast()){
			list.setActual(list.getActual()->getNext());
			list.getActual()->getData()->move(dT); 
		}
	}
	
	unsigned int EntityList::getSize(){
		return list.getSize();
	}	

	Entity* EntityList::operator[](unsigned int pos)
	{
		return list[pos];
	}
}//final do namespace List
