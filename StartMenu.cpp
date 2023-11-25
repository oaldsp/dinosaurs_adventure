#include "StartMenu.h"
#include "Game.h"//por causa do include bidirecional

StartMenu::StartMenu(Game* gameTemp): 
Menu(CoordF(0.0f, 0.0f)), 
State(stateID::menu), 
pGame(gameTemp){
	Text* temp = NULL;
	
	temp = new Text(CoordF(50.0f, 0.0f), "DINOSAUR'S ADVENTURE");
	temp->setFSize(150);
	VText.push_back(temp);
	
	temp = new Text(CoordF(50.0f, 150.0f), "A BATTLE OF EVOLUTION");
	temp->setFSize(75);
	VText.push_back(temp);
	
	temp = new Text(CoordF(50.0f, 250.0f), "1 - LEVEL 1");
	VText.push_back(temp);
	
	temp = new Text(CoordF(50.0f, 350.0f), "2 - LEVEL 2");
	VText.push_back(temp);
	
	temp = new Text(CoordF(50.0f, 450.0f), "3 - RANKING");
	VText.push_back(temp);
	
	temp = new Text(CoordF(50.0f, 550.0f), "*press the number to seleted*");
	temp->setFSize(50);
	VText.push_back(temp);

	max = 4; 
}

void StartMenu::start(){

}

void StartMenu::move(const float dt){

}

void StartMenu::plot(){
	backM.plot();
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
