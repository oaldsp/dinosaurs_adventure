#include "GraphicsManager.h"

#include <cstring>
#include <iostream>

/*
	Codigo reutilizado de "Burda Canal"
	Link: https://youtu.be/RFSOXXsm4Ug?si=ADNre21NtIXd3c5n
*/

#define WIDTH 1366
#define HEIGHT 768

namespace Managers {

    /* Singleton design pattern - Only one instance will be created */
    GraphicsManager* GraphicsManager::instance = nullptr;

    /* Returns a pointer to the Graphics. */
    GraphicsManager* GraphicsManager::getInstance() {
        if (instance == nullptr) {
            instance = new GraphicsManager();
        }
        return instance;
    }

    GraphicsManager::GraphicsManager() :
    window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Game", /*sf::Style::Titlebar |*/ sf::Style::/*Fullscreen*/Default | sf::Style::Close)),
    view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
    texturesMap(),
    fontsMap() { }

    GraphicsManager::~GraphicsManager() {
        std::map<const char*, sf::Texture*>::iterator it;

        for (it = texturesMap.begin(); it != texturesMap.end(); ++it) {
            delete (it->second);
        }

        delete (window);
    }

    /* Give a pointer to a body and it will be drawn to the screen. */
    void GraphicsManager::render(sf::RectangleShape* body) {
        window->draw(*body);
    }

    /* Give a pointer to a Text and it will be drawn to the screen */
    void GraphicsManager::render(sf::Text* text) {
        window->draw(*text);
    }

    /* Display everything that was drawn. */
    void GraphicsManager::display() {
        if (isWindowOpen())
            window->display();
    }

    /* Clear the window to re-display stuff. */
    void GraphicsManager::clear() {
        if (isWindowOpen())
            window->clear();
    }

    /* Returns if the window is open. */
    bool GraphicsManager::isWindowOpen() const {
        return window->isOpen();
    }

    /* CAUTION: Call the close window function - SFML window will close. */
    void GraphicsManager::closeWindow() {
        window->close();
    }

    /* Sets window size to its parameters */
    void GraphicsManager::setWindowSize(CoordU size) {
        window->setSize(sf::Vector2u(size.x, size.y));
        view.setSize(size.x, size.y);
        window->setView(view);
    }

    /* Returns the window size. */
    CoordU GraphicsManager::getWindowSize() const {
        return CoordU(window->getSize().x, window->getSize().y);
    }

    /* Returns the top left position of screen. */
    CoordF GraphicsManager::getTopLeftPosition() const {
        return CoordF(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
    }

    /* Changes the view position. */
    void GraphicsManager::centerView(CoordF pos) {
        view.setCenter(sf::Vector2f(pos.x, pos.y));
        window->setView(view);
    }

    /* Returns a texture to be used by an entity. */
    sf::Texture* GraphicsManager::loadTexture(const char* path) {
        /* Tries to find an existing texture linked by the path to it. */
        std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
        while (it != texturesMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }

    /* Returns a font pointer to be used by texts. */
    sf::Font* GraphicsManager::loadFont(const char* path) {
        /* Tries to find an existing font linked by the path to it */
        std::map<const char*, sf::Font*>::iterator it = fontsMap.begin();
        while (it != fontsMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        sf::Font* font = new sf::Font();

        if (!font->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        fontsMap.insert(std::pair<const char*, sf::Font*>(path, font));

        return font;
    }

    sf::RenderWindow* GraphicsManager::getWindow() const {
        return window;
    }

    float GraphicsManager::updateDeltaTime(){
    	dT = clk.getElapsedTime().asSeconds();
	clk.restart();
	
	return dT;
    }

} // namespace Managers
