#pragma once

#include "Coord.h"
#include <SFML/Graphics.hpp> 

class StaticAnimation{
private:
	sf::RectangleShape body;
public:
	StaticAnimation(const char* directory, CoordF pos, CoordF size, float scale);
	~StaticAnimation() = default;

	void updatePos(CoordF pos);
	void plot();
};
