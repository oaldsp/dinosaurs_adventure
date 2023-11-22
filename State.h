#pragma once 

class StateMachine;//por causa do include bidirecional

enum stateID{
	//Ao adicionar estados aumentar indice na destrutora do SateteMachine tb
	unknown,
	menu,
	level1
};

class State{
private:
	static StateMachine* pMachi;
	stateID id;
public:
	State(stateID idTemp = unknown);
	virtual ~State();

	void set_StateMachine(StateMachine* pMachiTemp);

	void changeState(stateID idTemp);

	stateID getID() const;

	virtual void move(const float dt)  = 0;
	virtual void plot()  = 0;
	virtual void reset() = 0;
};
