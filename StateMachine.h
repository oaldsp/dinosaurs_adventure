#pragma once

#include <map>

#include "State.h"

class StateMachine{
protected:
	stateID id;
	std::map<stateID, State*> states;
public:
	StateMachine();
	virtual ~StateMachine();

	void changeState(stateID idTemp);
	void exe(const float dt);

	stateID getID() const;
	void add(State* pState);
	void plot();
};
