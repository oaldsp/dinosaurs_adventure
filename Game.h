#pragma once

#include "Player.h"
#include "Projectile.h"
#include "Chick.h"
#include "Chicken.h"
#include "Rooster.h"
#include "Petroleum.h"
#include "Meteor.h"
#include "Ground.h"
#include "GraphicsManager.h"
#include "StaticAnimation.h"
#include "CollisionManager.h"
#include "EventsManager.h"
#include "EntityList.h"

class Game{
private:
	//colisoes
	List::EntityList mE;
	List::EntityList sE;
	Managers::CollisionManager GC;
	
	//Eventos
	EventsManager* pEvents;

	//grafico	
	Managers::GraphicsManager* pGrap; 	
	StaticAnimation background; 
	
	//objetos vivos
	Entities::Creature::Player p1;
	Entities::Projectile pp1;
	Entities::Creature::Chick c1;
	Entities::Creature::Chicken ce1;
	Entities::Creature::Rooster r1;

	//objetos fixos
	Entities::Obstacles::Petroleum e1;
	Entities::Obstacles::Meteor m1;
	Entities::Obstacles::Ground g1;
	Entities::Obstacles::Ground g2;
	Entities::Obstacles::Ground w1; 
	Entities::Obstacles::Ground w2; 
public:
	Game();
	~Game() = default;
	
	void start();	
	void exe();
}; 
