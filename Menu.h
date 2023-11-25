#pragma once 

#include "Text.h"
#include "Mcontrol.h"
#include <vector>

class Menu: public Ente{
protected:
	std::vector<Text*> VText;
	std::vector<Text*>::iterator it;
       	int selected;
	int min;
	int max;
	bool active;
	Mcontrol ctrl;
	StaticAnimation backM;
public:
	Menu(CoordF posTemp);
	virtual ~Menu();

	virtual void op1() = 0;
	virtual void op2() = 0;
	virtual void op3() = 0;
	virtual void op4() = 0;
};
