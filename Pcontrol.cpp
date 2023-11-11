#include "Pcontrol.h"
#include "Player.h"//por causa do include bidirecional

Pcontrol::Pcontrol(Entities::Creature::Player* pPlayerTemp):
Observer(), pPlayer(pPlayerTemp),
jump(""),left(""),right(""),attack(""){}

Pcontrol::~Pcontrol(){	
	pPlayer = NULL;
}

void Pcontrol::pressed(std::string keyTemp){
	if(NULL  != pPlayer){
		if(keyTemp == jump){
			//keysBool[jump] = true;
			pPlayer->jump();
		}if(keyTemp == left){
			//keysBool[left] = true;
			pPlayer->left();
		}if(keyTemp == right){
			//getKeysBool()->operator[](right) = true;
			pPlayer->right();
		}if(keyTemp == attack){
			//keysBool[attack] = true;
			pPlayer->attack();
		}
	}
}

void Pcontrol::released(std::string keyTemp){
	if(NULL  != pPlayer){
		//if(keyTemp == jump)
			//keysBool[jump] = false;
		//if(keyTemp == left)
			//keysBool[left] = false;
		//if(keyTemp == right)
			//keysBool[right] = false;
		//if(keyTemp == attack)
			//keysBool[attack] = false;
	}
}


void Pcontrol::setKeys(std::string jumpTemp, std::string leftTemp, std::string rightTemp, std::string attackTemp){
	jump   = jumpTemp;
	left   = leftTemp;
	right  = rightTemp;
	attack =  attackTemp;

	//std::map<sf::Keyboard::Key, bool>* keysBool= Input::getInstance().getKeysBool();
	//keysBool->insert(std::pair<std::string, bool>(jump,false));
	//keysBool->insert(std::pair<std::string, bool>(left,false));
	//keysBool->insert(std::pair<std::string, bool>(right,false));
	//keysBool->insert(std::pair<std::string, bool>(attack,false));
}
