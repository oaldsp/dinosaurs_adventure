#include "EventsManager.h"

//Inicializando atributo estatico
EventsManager* EventsManager::instance = NULL;

EventsManager::EventsManager():
pGrap(Managers::GraphicsManager::getInstance()),
pInput(Input::getInstance()),
pWindow(NULL){	
	if(NULL != pGrap)
		pWindow = pGrap->getWindow();
}

EventsManager::~EventsManager(){
	pInput   = NULL;
	pWindow  = NULL;
	instance = NULL;
}

EventsManager* EventsManager::getInstance(){
	if(NULL == instance)	
		instance = new EventsManager();
	return instance;
}

void EventsManager::libraryEvents(){
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
