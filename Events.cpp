#include "Events.h"

//Inicializando atributo estatico
Events* Events::instance = NULL;

Events::Events():
pGrap(Managers::Graphics::getInstance()),
pInput(Input::getInstance()),
pWindow(NULL){	
	if(NULL == pGrap)
		pWindow = pGrap->getWindow();
}

Events::~Events(){
	pInput   = NULL;
	pWindow  = NULL;
	instance = NULL;
}

Events* Events::getInstance(){
	if(NULL == instance)	
		instance = new Events();
	return instance;
}

void Events::LibraryEvents(){
	sf::Event event;
	
	while(pWindow->pollEvent(event)){
		if(event.type == sf::Event::Closed)
			pGrap->closeWindow();
		if(event.type == sf::Event::KeyPressed)
			pInput->keyPressed(event.key.code);
		if(event.type == sf::Event::KeyReleased)
			pInput->keyReleased(event.key.code);
	}
}
