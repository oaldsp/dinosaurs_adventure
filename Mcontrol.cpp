#include "Mcontrol.h"
#include "Menu.h"//por causa do include bidirecional

Mcontrol::Mcontrol(Menu* pMenuTemp):
Observer(), pMenu(pMenuTemp),
op1("1"), op2("2"), op3("3"), op4("4"){}

Mcontrol::~Mcontrol(){	
	pMenu = NULL;
}

void Mcontrol::pressed(std::string keyTemp){
	if(NULL  == pMenu){
		std::cout<<"ponteiro do player nulo"<<std::endl;
		exit(1);
	}if(keyTemp == op1){
		//pMenu->jump();
	}if(keyTemp == op2){
		//pMenu->left();
	}if(keyTemp == op3){
		//pMenu->right();
	}if(keyTemp == op4){
		//pMenu->attack();
	}
}

void Mcontrol::released(std::string keyTemp){

}
	
