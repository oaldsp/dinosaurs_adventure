#pragma once 

#include "Graphics.h"
#include "Input.h"

class Events{
private:
	Managers::Graphics* pGrap;
	Input* pInput;
	sf::RenderWindow* pWindow; 
	
	static Events* instance;
	Events();
public:
	~Events();
	
	static Events* getInstance();

	void  libraryEvents();// ve quais eventos a ibiblioteca chamou e repassa essas chamas para o gerenciador grafico
};
