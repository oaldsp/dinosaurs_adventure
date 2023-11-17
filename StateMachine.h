#pragma once

#include <vector>

#include "State.h"

class StateMachine{
protected:
	stateID id;
	std::vector<State*> states;
public:
	StateMachine();
	virtual ~StateMachine();

	void changeState(stateID idTemp);
	void exe(const float dt);

	stateID getID() const;
	void add(State* pState);

};
