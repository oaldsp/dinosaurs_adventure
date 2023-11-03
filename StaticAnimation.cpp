#include "StaticAnimation.h"
#include "Graphics.h"

StaticAnimation::StaticAnimation(const char* directory, CoordF pos, CoordF size, float scale):
body(sf::Vector2f(size.x,size.y)){
	body.setPosition(sf::Vector2f(pos.x, pos.y));
       	body.setScale(sf::Vector2f(scale, scale));
	body.setTexture(Managers::Graphics::getInstance()->loadTexture(directory));
}

void StaticAnimation::updatePos(CoordF pos){
	body.setPosition(sf::Vector2f(pos.x,pos.y));
}

void StaticAnimation::plot(){
	Managers::Graphics::getInstance()->render(&body);
}
