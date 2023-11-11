#include "Player.h"

namespace Entities{
	namespace Creature{

		Player::Player(CoordF  posTemp):
		Creature(posTemp, CoordF(P_SIZE_X,P_SIZE_Y)),
		ctrl(this)
		/*,isP1(true)*/{			
			start();		
		}

		void Player::damage(unsigned int damage){
			int life = this->getLife();
			life-=damage;
			if(life <= 0){
				cout << "VOCE PERDEU" << endl;
				exit(1);
			}	
		}
		
		void Player::move(float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();
			
			time+=dT;
			/*
			float b = 0.9936315;
			time += dT/sqrt(1.0f - b);
		       	//printf("|%f|", b);
			while(true){
			if(time < 0.90f){
				b+=0.0000001;
				printf("|-(%f)|, b");
			}else if(time > 1.10f){
				b-=0.0000001;
				printf("|+(%f)|, b");
			}else{
				printf("|%f|", b);
				exit(1);
			}
			}
			*/
			this->getShape()->updatePos(posTemp);	
			//this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*time + 25.0f*time*time/2));
			if(time < 2.0f)
				this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y - speedTemp.y*dT /*+ 25.0f*dT*dT/2*/));
			else if(time < 4.0f)
				this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*dT /*+ 25.0f*dT*dT/2*/));
			else
				time=0;
		}

		void Player::start(){
			this->getShape()->setTexture("texture/player.png");
			this->setID(player);
			this->setLife(P_LIFE);
			this->setSpeedX(0.0f);
			time=0;
		}

		void Player::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case chicken:
				this->damage(101);
				break;
			case ground:
				time *= 0.0f;//zero o tempo para o jump
				this->moveAway(slamEntity, difference);
				break;
			default:
				break;
			}	
		}

		Pcontrol* Player::getCtrl(){
			return &ctrl;
		}

		void Player::jump(){
			this->setSpeedY(P_SPEED_Y);
		}

		void Player::left(){
			this->setSpeedX(-P_SPEED_X);
		}

		void Player::right(){
			this->setSpeedX(P_SPEED_X);
		}

		void Player::attack(){
			
		}

		void Player::stop(){
			this->setSpeedX(0.0f);
		}

	}//Final do namespace Creature 
}//Final do namespace Entities
