#pragma once

#include "player.h"
#include "Graphics.h"

class Game{
private:
	Managers::Graphics* pGrap; 
	//Player p1;
public:
	Game();
	~Game();
	
	void exe();
}; 
