#pragma once

#include "Player.h"
#include "Chicken.h"
#include "Ground.h"
#include "Graphics.h"
#include "StaticAnimation.h"
#include "Collision.h"
#include "Events.h"
#include "EntityList.h"

class Game{
private:
	//colisoes
	List::EntityList mE;
	List::EntityList sE;
	Managers::Collision GC;
	
	//Eventos
	Events* pEvents;

	//grafico	
	Managers::Graphics* pGrap; 	
	StaticAnimation background; 
	
	//objetos vivos
	Entities::Creature::Player p1;
	Entities::Creature::Chicken c1;
	
	//objetos fixos
	Entities::Obstacles::Ground g1;
	Entities::Obstacles::Ground w1; 
	Entities::Obstacles::Ground w2; 
public:
	Game();
	~Game() = default;
	
	void start();	
	void exe();
}; 
