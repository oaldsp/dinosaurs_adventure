#pragma once 

#include "Text.h"
#include "Mcontrol.h"
#include <vector>

class Menu: public Ente{
private:
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
	virtual void exe() = 0;
};
