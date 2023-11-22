#include "Text.h"

Text::Text(CoordF posTemp, std::string infoTemp):Ente(posTemp){
	this->setPos(posTemp);
	info = infoTemp;
	text.setString(infoTemp);
	text.setOrigin(0.0f, 0.0f);
	text.setCharacterSize(10);
	text.setPosition(sf::Vector2f(posTemp.x, posTemp.y));
	text.setFillColor(sf::Color::Black);
}

void Text::setFSize(const unsigned int sizeTemp){
	text.setCharacterSize(sizeTemp);
}

void Text::setColor(const unsigned int r,const unsigned int g,const unsigned int b){
	text.setFillColor(sf::Color(r, g, b));
}

void Text::plot(){
	getGrap()->render(&text);
}
