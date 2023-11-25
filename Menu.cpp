#include "Menu.h"

Menu::Menu(CoordF posTemp):Ente(posTemp),
selected(0), min(0), max(3), active(true), ctrl(this),
backM(CoordF(0.0f, 0.0f), CoordF(1366.0f, 768.0f)){
	backM.setTexture("texture/backgroundM.jpg");
}

Menu::~Menu(){
	Text* temp = NULL;
       	while(VText.size() != 0){
		temp = VText.back();
		delete(temp);
		VText.pop_back();
	}
	VText.clear();
}

