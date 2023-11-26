#include "StaticAnimation.h"
#include "GraphicsManager.h"

StaticAnimation::StaticAnimation(CoordF pos, CoordF size):
body(sf::Vector2f(size.x,size.y)){
	body.setPosition(sf::Vector2f(pos.x, pos.y));
	body.setScale(sf::Vector2f(1.0f, 1.0f));
}
void StaticAnimation::changeSize(CoordF sizeTemp){
	body.setSize(sf::Vector2f(sizeTemp.x, sizeTemp.y));
}

void StaticAnimation::changeScale(float scale){
	body.setScale(sf::Vector2f(scale, scale));
}

void StaticAnimation::updatePos(CoordF pos){
	body.setPosition(sf::Vector2f(pos.x,pos.y));
}

void StaticAnimation::plot(){
	Managers::GraphicsManager::getInstance()->render(&body);
	//body.setOutlineThickness(3);
	//body.setOutlineColor(sf::Color(255, 0, 0));
}

void StaticAnimation::setTexture(const char* directory){
	body.setTexture(Managers::GraphicsManager::getInstance()->loadTexture(directory));
}
