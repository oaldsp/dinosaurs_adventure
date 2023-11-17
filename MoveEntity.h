#pragma once

#include "Entity.h"
#include  "StaticAnimation.h"

namespace Entities{

	class MoveEntity:public Entity{
	private:
		bool live;
		float time;
		StaticAnimation shape;
	public:
		MoveEntity(CoordF posTemp = CoordF(0.f, 0.f), CoordF sizeTemp = CoordF(0.f, 0.f));
		~MoveEntity() =  default;

		void plot();
		
		bool getLive();
		void setLive(bool temp);
		
		float getTime() const;
		void setTime(const float timeTemp);
		
		StaticAnimation* getShape();

		//metodos virtuais puros 
		virtual void move(const float dT) = 0;
		virtual void start() = 0;
		virtual void collision(Entity* slamEntity, CoordF differencei) = 0;
		virtual int getAttribute() const=  0;
	};
}//Final do namespace Entities
