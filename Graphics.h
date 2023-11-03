#pragma once

#include "coord.h"
#include <SFML/Graphics.hpp>

#include <map>

namespace Managers {

    class Graphics {
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const char*, sf::Texture*> texturesMap;
        std::map<const char*, sf::Font*> fontsMap;
	sf::Clock clk;
	float dT;
        
        /* Singleton design pattern */
        static Managers::Graphics* instance;
        Graphics();

    public:
        ~Graphics();

        static Graphics* getInstance();

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

        //float updateDeltaTime();

        sf::RenderWindow* getWindow() const;

	void updateDeltaTime();
    };

} // namespace Managers
