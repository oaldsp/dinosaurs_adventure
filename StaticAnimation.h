#pragma once

#include "Coord.h"
#include <SFML/Graphics.hpp>

class StaticAnimation{
private:
	sf::RectangleShape body;
public:
	StaticAnimation(CoordF pos = CoordF(0.0f,0.0f), CoordF size =  CoordF(0.0f, 0.0f));
	~StaticAnimation() = default;

	void changeScale(float scale);
	void updatePos(CoordF pos);
	void plot();
	void setTexture(const char* directory);
};

