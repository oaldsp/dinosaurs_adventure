#include "Input.h"
#include "Observer.h"//por causa de include bidirecional

//Aterrando ponteiro statico
Input* Input::instance(NULL);

Input::Input(){
	//movimentacao do player	
	keysMap[sf::Keyboard::A] = "A";
	keysMap[sf::Keyboard::W] = "W";
	keysMap[sf::Keyboard::S] = "S";
	keysMap[sf::Keyboard::D] = "D";
	
	keysMap[sf::Keyboard::Left] = "<";
	keysMap[sf::Keyboard::Up] = "^";
	keysMap[sf::Keyboard::Down] = "*";
	keysMap[sf::Keyboard::Right] = ">";

	keysMap[sf::Keyboard::Num1] = "1";
	keysMap[sf::Keyboard::Num2] = "2";
	keysMap[sf::Keyboard::Num3] = "3";
	keysMap[sf::Keyboard::Num4] = "4";
	
	keysMap[sf::Keyboard::Escape] = "esc";
}

Input::~Input(){
	observers.clear();
	keysMap.clear();
	instance = NULL;
}

Input* Input::getInstance(){
	if(NULL == instance)
		instance = new Input();
	return instance;
}

void Input::add(Observer* obTemp){
	observers.push_back(obTemp);
}

void Input::remove(Observer* obTemp){
	observers.remove(obTemp); 
}

void Input::keyPressed(sf::Keyboard::Key keyTemp){
	//std::cout << mapToString(keyTemp) << std::endl;
	for(it = observers.begin(); it != observers.end(); it++)
		(*it)->pressed(mapToString(keyTemp));
}

void Input::keyReleased(sf::Keyboard::Key keyTemp){
	for(it = observers.begin(); it != observers.end(); it++)
		(*it)->released(mapToString(keyTemp));

}

std::string Input::mapToString(sf::Keyboard::Key keyTemp){
	return keysMap[keyTemp] == "" ? "Erro" : keysMap[keyTemp];
}
