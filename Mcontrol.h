#pragma once

#include "Observer.h"

class Menu;//por causa do include bidirecional 

class Mcontrol: public Observer{
private:
	Menu* pMenu;
	const std::string op1;
	const std::string op2;
	const  std::string op3;
	const std::string op4;
public:
	Mcontrol(Menu* pMenuTemp = NULL);
	~Mcontrol();

	void pressed(std::string keyTemp);
	void released(std::string keyTemp);
};
