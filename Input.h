#pragma once 

#include <list>
#include <map>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Observer;//pois observer inclui input tb.

class Input{
private:
	std::list<Observer*> observers;
	std::list<Observer*>::iterator it;

	std::map<sf::Keyboard::Key, std::string> keysMap;
	
	static Input* instance;
	Input();
public:
	~Input();

	static Input* getInstance();

	void add(Observer* obTemp);
	void remove(Observer* obTemp);

	void keyPressed(sf::Keyboard::Key keyTemp);
	void keyReleased(sf::Keyboard::Key keyTemp);
	std::string mapToString(sf::Keyboard::Key keyTemp);
};
