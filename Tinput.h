#pragma once

#include "Observer.h"
#include <iostream>

class Tinput: public Observer{
private:
public:
	Tinput() = default;
	~Tinput() = default;
      	void pressed(std::string keyTemp);
	void released(std::string keyTemp);
};
