#include "Observer.h"

Observer::Observer(){
	pInput = Input::getInstance();
	pInput->add(this);
}
	
Observer::~Observer (){
	pInput->remove(this);
}
