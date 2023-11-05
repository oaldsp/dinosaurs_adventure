#include "StaticAnimation.h"
#include "Graphics.h"

StaticAnimation::StaticAnimation(CoordF pos, CoordF size):
body(sf::Vector2f(size.x,size.y)){
	body.setPosition(sf::Vector2f(pos.x, pos.y));
	body.setScale(sf::Vector2f(1.0f, 1.0f));
	body.setTexture(Managers::Graphics::getInstance()->loadTexture("texture/ground.jpg"));
}

void StaticAnimation::changeScale(float scale){
	body.setScale(sf::Vector2f(scale, scale));
}

void StaticAnimation::updatePos(CoordF pos){
	body.setPosition(sf::Vector2f(pos.x,pos.y));
}

void StaticAnimation::plot(){
	Managers::Graphics::getInstance()->render(&body);
}

void StaticAnimation::setTexture(const char* directory){
	body.setTexture(Managers::Graphics::getInstance()->loadTexture(directory));
}
