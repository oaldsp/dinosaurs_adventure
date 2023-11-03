#pragma once

#include "Player.h"
#include "Graphics.h"
#include "StaticAnimation.h"

class Game{
private:
	Managers::Graphics* pGrap; 
	Player p1;
	StaticAnimation background;
public:
	Game();
	~Game() = default;
	
	void exe();
}; 
