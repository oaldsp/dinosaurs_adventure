#pragma once 

#include "Entity.h"
#include "List.h"

using namespace Entities;

namespace List{

	class EntityList{
	private:
		List<Entity> list;
	public:
		EntityList() = default;
		~EntityList();
		
		void addEntity(Entity* pTemp);
		void removeEntity(Entity* pTemp);
		void removeEntity(unsigned int pos);
		unsigned int getSize();
		Entity* operator[](unsigned int pos);
	}; 
}//final do namespace List
