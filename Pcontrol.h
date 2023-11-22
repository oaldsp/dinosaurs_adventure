#pragma once

#include "Observer.h"

namespace Entities::Creature{
	class Player;//porcausa do include bidirecional
}

class Pcontrol: public Observer{
private:
	Entities::Creature::Player* pPlayer;
	std::string jump;
	std::string left;
	std::string right;
	std::string attack;
public:
	Pcontrol(Entities::Creature::Player* pPlayerTemp = NULL);
	~Pcontrol();

	void pressed(std::string keyTemp);
	void released(std::string keyTemp);
	void setKeys(std::string jumpTemp, std::string leftTemp, std::string rightTemp, std::string attackTemp); 
};
