#include "State.h"
#include "StateMachine.h"//por causa do include bidirecional
#include <cstddef>

StateMachine *State::pMachi(StateMachine::getInstance());

State::State(stateID idTemp):id(idTemp)
{
	pMachi->add(this);
}

State::~State(){
	pMachi =  NULL;
}

void State::set_StateMachine(StateMachine* pMachiTemp) 
    {
        pMachi = pMachiTemp;
    }

const stateID State::getID() const{
	return id;
}
