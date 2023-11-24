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
#include "LevelOne.h"
#include "StateMachine.h"
#include "LevelTwo.h"

class Game{
private:
	LevelOne level_one;
	LevelTwo level_two;
	
	EventsManager* pEvents;
	StateMachine* pStateMachine;

	//grafico	
	Managers::GraphicsManager* pGrap; 	
public:
	Game();
	~Game() = default;
	
	void start();	
	void exe();
}; 
