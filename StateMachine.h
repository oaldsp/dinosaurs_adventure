#pragma once

#include <vector>

#include "State.h"

class StateMachine{
protected:
	stateID id;
	std::vector<State*> states;
	static StateMachine* instance;
    StateMachine();
public:
	virtual ~StateMachine();

	static StateMachine* getInstance();

	void changeState(stateID idTemp);
	void exe(const float dt);

	stateID getID() const;
	void add(State* pState);

};
