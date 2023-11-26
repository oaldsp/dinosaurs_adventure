#include "Ente.h"

Managers::GraphicsManager* Ente::pGM = Managers::GraphicsManager::getInstance();

Ente::Ente(CoordF posTemp):pos(posTemp), speed(CoordF(0.0f,0.0f)){}

void Ente::setPos(CoordF posTemp){
	pos=posTemp;
}

void Ente::setSize(CoordF sizeTemp){
	size=sizeTemp;
}

void Ente::setID(ID idTemp){
	id=idTemp;
}
	
void Ente::setSpeedX(const float xTemp){
	speed.x = xTemp;
}	
		
void Ente::setSpeedY(const float yTemp){
	speed.y = yTemp;
}

CoordF Ente::getSize() const{
	return size;
}

CoordF Ente::getPos() const{
	return pos;
}

ID Ente::getID() const{
	return id;
}

CoordF Ente::getSpeed() const{
	return speed;
}

Managers::GraphicsManager* Ente::getGrap(){
	return pGM;
}
