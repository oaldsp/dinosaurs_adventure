#pragma once

#include "GraphicsManager.h"
#include "Ente.h"
#include "Coord.h"
#include <string>

class Text:public Ente{
private:
	std::string info;
	sf::Text text;
public:
	Text(CoordF posTemp = CoordF(0.0f, 0.0f), std::string infoTemp = "");
	~Text() = default;

	void setFSize(const unsigned int sizeTemp);
	void setColor(const unsigned int r,const unsigned int g, const unsigned int b);
	
	void plot();
	void move(const float dT);
	void start();
};
