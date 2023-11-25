#include "Text.h"

Text::Text(CoordF posTemp, std::string infoTemp):Ente(posTemp){
	this->setPos(posTemp);
	info = infoTemp;
	text.setString(infoTemp);
	text.setOrigin(0.0f, 0.0f);
	text.setFont(*getGrap()->loadFont("texture/font.otf"));
	text.setCharacterSize(100);
	text.setPosition(sf::Vector2f(posTemp.x, posTemp.y));
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1.0f);
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

void Text::move(const float dT){

}

void Text::start(){

}
