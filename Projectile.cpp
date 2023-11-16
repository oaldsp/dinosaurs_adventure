#include "Projectile.h"

namespace Entities{

	Projectile::Projectile(MoveEntity* pOwnerTemp): MoveEntity(CoordF(-100.0f, -100.0f), CoordF(0.0f, 0.0f)), pOwner(pOwnerTemp){
		start();
	}

	Projectile::~Projectile(){
		pOwner = NULL;
	}

	void Projectile::move(const float dT){
		CoordF posTemp = this->getPos();
		CoordF speedTemp = this->getSpeed();
		//printf("\n%f|%f\n",  getPos().x, getPos().y);
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
		this->setPos(CoordF(posTemp.x + speedTemp.x*dT, posTemp.y + speedTemp.y*getTime() /*+ a*getTime()*getTime()/2*/));
		/*
			USANDO FORMULA DE MRUV PARA DESLOCAMENTO EM Y
			S=So+Vot+at^2/2
		*/
			
		//this->setSpeedY(getSpeed().y + a* dT);//V = V0 + at (ATUALIZA VELOCIDADE PARA PROXIMA EXECUCAO)
	}

	void Projectile::start(){
		this->setID(projectile);
		this->setSpeedX(0.0f);
		this->setSpeedY(0.0f);	
	}

	void Projectile::collision(Entity* slamEntity, CoordF differencei){
		switch(slamEntity->getID()){
		case ground:
			printf("Bateu");
			setTime(0.0f);
			this->setSpeedX(0.0f);
			this->setSpeedY(0.0f);	
			this->setPos(CoordF(0.0f, 0.0f));
			break;
		default:
			break;
		}
	}

	void Projectile::launch(CoordF posTemp, CoordF posSpeed){
		this->setPos(posTemp);
		//this->setSpeedY(-PR_SPEED_Y);
		this->getShape()->setTexture("texture/prctP.png");
		this->setSize(CoordF(50.0f, 50.0f));
		printf("(|%f|%f|%f\n)", this->getPos().x, this->getSpeed().x, this->getSize().x);
		printf("(|%f|%f|%f\n\n)", this->getPos().y, this->getSpeed().y, this->getSize().y);
		if(posSpeed.x >= 0.0f)
			this->setSpeedX(PR_SPEED_X);
		else
			this->setSpeedX(-PR_SPEED_X);

	} 

	int Projectile::getAttribute() const{
		return 1;
	}
}//Final do namespace Entities;
