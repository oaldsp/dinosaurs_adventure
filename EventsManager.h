#pragma once 

#include "GraphicsManager.h"
#include "Input.h"

namespace Managers{

	class EventsManager{
	private:
		Managers::GraphicsManager* pGrap;
		Input* pInput;
		sf::RenderWindow* pWindow; 
		
		static EventsManager* instance;
		EventsManager();
	public:
		~EventsManager();
		
		static EventsManager* getInstance();

		void  libraryEvents();// ve quais eventos a ibiblioteca chamou e repassa essas chamas para o gerenciador grafico
	};
}//Final do namespace Managers
