#include "State.h"
#include "StateMachine.h"//por causa do include bidirecional

State::State(StateMachine* pMachiTemp, stateID idTemp):pMachi(pMachiTemp), id(idTemp){}

State::~State(){
	pMachi =  NULL;
}

void State::changeState(stateID idTemp){
	id = idTemp;
}

stateID State::getID() const{
	return id;
}
