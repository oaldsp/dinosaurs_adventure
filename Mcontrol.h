#pragma once

#include "Observer.h"

class Menu;//por causa do include bidirecional 

class Mcontrol: public Observer{
private:
	Menu* pMenu;
	std::string op1;
	std::string op2;
	std::string op3;
	std::string op4;
public:
	Mcontrol(Menu* pMenuTemp = NULL);
	~Mcontrol();

	void pressed(std::string keyTemp);
	void released(std::string keyTemp);
};
