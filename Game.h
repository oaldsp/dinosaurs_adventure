#pragma once

#include "Player.h"
#include "Ground.h"
#include "Graphics.h"
#include "StaticAnimation.h"
#include "Collision.h"
#include "EntityList.h"

class Game{
private:
	//colisoes
	List::EntityList mE;
	List::EntityList sE;
	Managers::Collision GC;
	
	//grafico	
	Managers::Graphics* pGrap; 	
	StaticAnimation background; 
	
	//objetos
	Entities::Player p1;
	Entities::Obstacles::Ground g1; 
public:
	Game();
	~Game() = default;
	
	void start();	
	void exe();
}; 