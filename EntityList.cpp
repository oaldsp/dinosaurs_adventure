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
		/*Element<TL>* aux;// = list.getFirst();
		while(NULL != aux){
			(aux->getData)->plot();
			aux = aux->getNext(); 
		}*/
	}

	unsigned int EntityList::getSize(){
		return list.getSize();
	}	

	Entity* EntityList::operator[](unsigned int pos)
	{
		return list[pos];
	}
}//final do namespace List
