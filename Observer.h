#pragma once

#include "Input.h"

class Observer{
private:
	Input* pInput;
	std::map<sf::Keyboard::Key, bool> keysBool;
public:
	Observer();
	virtual ~Observer();

	std::map<sf::Keyboard::Key, bool>* getKeys(); 

	virtual void pressed(std::string keyTemp) = 0;
	virtual void released(std::string keyTemp) = 0;
};
