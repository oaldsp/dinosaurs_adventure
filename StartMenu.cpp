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
	
	temp = new Text(CoordF(50.0f, 450.0f), "3 - TWO PLAYERS");
	VText.push_back(temp);

	temp = new Text(CoordF(50.0f, 550.0f), "4 - RANKING");
	VText.push_back(temp);
	
	temp = new Text(CoordF(50.0f, 650.0f), "*press the number to be seleted*");
	temp->setFSize(50);
	VText.push_back(temp);

	max = 4; 
}

void StartMenu::addLevel(Levels::Level* levelTemp){
	levels.push_back(levelTemp);
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
	pGM->closeWindow();
}

void StartMenu::op1(){
	pMachi->changeState(level1);	
}

void StartMenu::op2(){
	pMachi->changeState(level2);	
}

void StartMenu::op3(){
	int size = levels.size();
	for(int i =0; i<size; i++)
		levels.at(i)->createP2();	
}

void StartMenu::op4(){
	
}
