#pragma once

#include "Input.h"

class Observer{
private:
	Input* pInput;
public:
	Observer();
	virtual ~Observer();
	virtual void pressed(std::string keyTemp) = 0;
	virtual void released(std::string keyTemp) = 0;
};
