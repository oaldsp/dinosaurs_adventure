#include "StateMachine.h"
#include <iostream>

StateMachine* StateMachine::instance = nullptr;

StateMachine* StateMachine::getInstance() 
{
    if (instance == nullptr) 
    {
        instance = new StateMachine();
    }
    return instance;
}

StateMachine::StateMachine():
    id(menu)
{

}

StateMachine::~StateMachine(){
	std::map<stateID, State*>::iterator it;
	for(it = states.begin(); it != states.end(); it++)
		delete (it->second);
}

void StateMachine::changeState(stateID idTemp){
	id = idTemp;
	states[id]->reset();
}

void StateMachine::exe(const float dt){
	//std::cout << states[id]<< '\n';
	states[id]->move(dt);
	states[id]->plot();
}

stateID StateMachine::getID() const{
	return id;
}

void StateMachine::add(State* pState){
	if( NULL == pState){
		std::cout << "Erro, ponteiro nulo" << std::endl;
		exit(1);
	}
	states[pState->getID()] = pState;
}

void StateMachine::plot(){
	states[id]->plot();
}
