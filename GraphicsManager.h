#pragma once

#include "Coord.h"
#include <SFML/Graphics.hpp>

#include <map>

/*
	Codigo reutilizado de "Burda Canal"
	Link: https://youtu.be/RFSOXXsm4Ug?si=ADNre21NtIXd3c5n 
*/

namespace Managers {

    class GraphicsManager{
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const char*, sf::Texture*> texturesMap;
        std::map<const char*, sf::Font*> fontsMap;
	sf::Clock clk;
	float dT;
        
        /* Singleton design pattern */
        static Managers::GraphicsManager* instance;
        GraphicsManager();

    public:
        ~GraphicsManager();

        static GraphicsManager* getInstance();

        void render(sf::RectangleShape* body);

        void render(sf::Text* text);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        void setWindowSize(CoordU size);

        CoordU getWindowSize() const;

        CoordF getTopLeftPosition() const;

        void centerView(CoordF pos);

        sf::Texture* loadTexture(const char* path);

        sf::Font* loadFont(const char* path);

        float updateDeltaTime();

        sf::RenderWindow* getWindow() const;
    };

} // namespace Managers
