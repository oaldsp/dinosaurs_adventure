#include "Projectile.h"

namespace Entities{

	Projectile::Projectile(MoveEntity* pOwnerTemp): 
	MoveEntity(CoordF(-100.0f, -100.0f), 
	CoordF(0.0f, 0.0f)), 
	pOwner(pOwnerTemp),
	launched(false)
	{
		start();
	}

	Projectile::~Projectile(){
		pOwner = NULL;
	}

	void Projectile::move(const float dT){
		//printf("\n%f|%f\n",  getSpeed().x, getSpeed().y);
		//printf("%f|%f\n",  getPos().x, getPos().y);
		if(launched){	
			CoordF posTemp = this->getPos();
			CoordF speedTemp = this->getSpeed();
		
			float a = getG();
			if(getSpeed().y >= 0.0f)
				a -=(getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*PR_M);
			else
				a +=(getK()*getSize().x*getSize().x*speedTemp.y*speedTemp.y)/(2*PR_M);
			/*
				Formula da aceleracao considerando arasto
				a = g - (K*x^2*v^2) /2m
			*/
			setTime(getTime() + dT);
						
			this->getShape()->updatePos(posTemp);	
			this->setPos(CoordF(posTemp.x  + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() + a*getTime()*getTime()/2));
			/*
				USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
				S=So+Vot+at^2/2
			*/
				
			this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
		}
	}

	void Projectile::start(){
		this->setID(projectile);
		this->setSpeedX(0.0f);
		this->setSpeedY(0.0f);	
	}

	void Projectile::reset(const Entity* slamEntity){
		if(slamEntity != pOwner){
			launched = false;
			setTime(0.0f);
			this->setPos(CoordF(-100.0f, -100.0f));
			this->getShape()->updatePos(getPos());//Muda no StaticAnimation
		}
	}

	void Projectile::collision(Entity* slamEntity, CoordF difference){
		switch(slamEntity->getID()){
		case ground:
			reset(slamEntity);
			break;
		case petroleum:
			reset(slamEntity);
			break;
		case rooster:
			reset(slamEntity);
			break;
		case chick:
			reset(slamEntity);
			break;
		case chicken:
			reset(slamEntity);
			break;
		case player:
			reset(slamEntity);	
			break;
		default:
			break;
		}
	}

	void Projectile::launch(CoordF posOwner, CoordF speedTemp){
		if(!launched){	
			launched = true;
			setTime(0.0f);
			this->setPos(posOwner);//Muda no Ente
			this->getShape()->updatePos(getPos());//Muda no StaticAnimation
		
			this->setSpeedY(-PR_SPEED_Y);	
			if(speedTemp.x > 0.0f)
				this->setSpeedX(PR_SPEED_X);
			else
				this->setSpeedX(-PR_SPEED_X);
		}
	} 

	int Projectile::getAttribute() const{
		return 1;
	}
}//Final do namespace Entities;
