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
    id(unknown)
{
	printf("flagSM");
    //states.resize(3);
}

StateMachine::~StateMachine(){
for(int i=0; i<2; i++)
	delete states[i];
}

void StateMachine::changeState(stateID idTemp){
	id = idTemp;
	states[id]->reset();
}

void StateMachine::exe(const float dt){
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
