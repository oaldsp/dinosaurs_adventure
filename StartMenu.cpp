#include "StartMenu.h"
#include "Game.h"//por causa do include bidirecional

StartMenu::StartMenu(Game* gameTemp): 
Menu(CoordF(0.0f, 0.0f)), 
State(static_cast<StateMachine*>(gameTemp), stateID::menu), 
pGame(gameTemp){
	Text* temp = NULL;
	
	temp = new Text(CoordF(0.0f, 0.0f), "LEVEL 1");
	VText.push_back(temp);
	
	temp = new Text(CoordF(0.0f, 50.0f), "LEVEL 2");
	VText.push_back(temp);
	
	temp = new Text(CoordF(0.0f, 100.0f), "LEVEL 3");
	VText.push_back(temp);
	
	temp = new Text(CoordF(0.0f, 150.0f), "LEVEL 4");
	VText.push_back(temp);

	max = 4; 
}

void StartMenu::start(){

}

void StartMenu::move(const float dt){

}

void StartMenu::plot(){
	//backM.plot();
	//for(int i=0; i<1000; i++)
	//	printf("AAAAAA");
	for(it = VText.begin(); it != VText.end(); it++)
		(*it)->plot();
}

void StartMenu::reset(){

}

void StartMenu::op1(){

}

void StartMenu::op2(){

}

void StartMenu::op3(){

}

void StartMenu::op4(){

}
