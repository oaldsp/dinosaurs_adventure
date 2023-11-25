#include "Player.h"

namespace Entities{
	namespace Creature{
		
		Player::Player(CoordF  posTemp, Projectile* prctTemp):
		Creature(posTemp, CoordF(P_SIZE_X,P_SIZE_Y)),
		chao(true), ctrl(this), prct(prctTemp){			
			start();		
		}

		Player::~Player(){
			prct = NULL;
		}

		void Player::damage(const float damage){
			setLife(getLife() - damage);
			if(getLife() <= 0.0f){
				cout << "VOCE PERDEU" << endl;
				exit(1);
			}	
		}
		
		void Player::move(const float dT){
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();

			float a = getG();
			if(getSpeed().y >= 0.0f)
				a -=(getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*P_M);
			else
				a +=(getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*P_M);
			/*
				Formula da aceleracao considerando arasto
					a = g - (K*x^2*v^2) /2m
			 */
			setTime(getTime() + dT);
				
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() + a*getTime()*getTime()/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
			
			this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
		}

		void Player::start(){
			prct = new Projectile(this);
			this->getShape()->setTexture("texture/player.png");
			prct->getShape()->setTexture("texture/prctP.png");
			prct->getShape()->changeSize(CoordF(PP_SIZE_X, PP_SIZE_Y));//Muda no StaticAnimation
			prct->setSize(CoordF(PP_SIZE_X, PP_SIZE_Y));//Muda no Ente
			this->setID(player);
			this->setLife(P_LIFE);
			stop();
		}

		void Player::collision(Entity* slamEntity, CoordF difference){
			switch(slamEntity->getID()){ 
			case chick:
				this->damage(10.0f);
				break;
			case projectile:
				if(slamEntity != prct)
					this->damage(10.0f);
				break;
			case chicken:
				this->damage(5.0f);
				break;
			case rooster:
				this->moveAway(slamEntity, difference);
				this->repel(slamEntity);
				if(slamEntity->getAttribute())
					this->damage(25.0f);
				else 
					this->damage(10.0f);
				break;
			case ground:
				chao = true;
				setTime(0.0f);//zero o tempo para o jump
				this->setSpeedY(slamEntity->getAttribute()*0.1f*getSpeed().y);
				this->moveAway(slamEntity, difference);
				break;
			case petroleum:
				chao = false;
				setTime(0.0f);//zero o tempo para o jump
				this->setSpeedX(getSpeed().x/(0.1f*slamEntity->getAttribute()));
				this->moveAway(slamEntity, difference);
				break;
			case meteor:
				this->moveAway(slamEntity, difference);
				this->repel(slamEntity);
				this->damage(10.0f*slamEntity->getAttribute());
				break;
			default:
				break;
			}	
		}

		void Player::repel(Entity* slamEntity){
			if(this->getPos().x >= slamEntity->getPos().x)
				setPos(CoordF(getPos().x + slamEntity->getSize().x, getPos().y));
			else
				setPos(CoordF(getPos().x - slamEntity->getSize().x, getPos().y));
		}
	
		int Player::getAttribute() const{
			return 1;
		}

		Pcontrol* Player::getCtrl(){
			return &ctrl;
		}

		void Player::jump(){
			if(chao){       	
				this->setPos(CoordF(getPos().x, getPos().y - 10.0f));
				this->setSpeedY(-P_SPEED_Y);
			}
			chao = false;
		}

		void Player::left(){
			this->setSpeedX(-P_SPEED_X);
		}

		void Player::right(){
			this->setSpeedX(P_SPEED_X);
		}

		void Player::attack(){
			/*VER PORQUE AO COLOCAR ESSES CARAS NO START DA "SEGFOU"*/
			prct->getShape()->setTexture("texture/prctP.png");
			prct->getShape()->changeSize(CoordF(PP_SIZE_X, PP_SIZE_Y));//Muda no StaticAnimation
			prct->setSize(CoordF(PP_SIZE_X, PP_SIZE_Y));//Muda no Ente
			prct->launch(this->getPos(), this->getSpeed());	
		}

		void Player::stop(){
			this->setSpeedX(0.0f);
		}

	}//Final do namespace Creature 
}//Final do namespace Entities
