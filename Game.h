#pragma once

#include "Player.h"
#include "Graphics.h"
#include "StaticAnimation.h"

class Game{
private: 
	Managers::Graphics* pGrap; 
	Entities::Player p1;
	StaticAnimation background; 
public:
	Game();
	~Game() = default;
	
	void start();	
	void exe();
}; 
