#pragma once //evitar que o arquivo seja incluido mais de uma vez.

#include <iostream>
using namespace std;

template <typename TIPO>//para tornar a funcao mais generica.
class Coord{
private:
       	TIPO x;
	TIPO y;
public:
	Coord(TIPO x,TIPO y);
	Coord();
	~Coord();
	
	TIPO getX();
	TIPO getY();

	//operadores para facilitar a utilizacao das coordenadas.
	//sem retorno.
	void operator=(Coord<TIPO> temp);
       	void operator+=(Coord<TIPO> temp);
	void operator-=(Coord<TIPO> temp);
	void operator*=(double k);
	void operator/=(double k);
	
	//com retorno coord.
	Coord<TIPO> operator+(Coord<TIPO> temp);
	Coord<TIPO> operator-(Coord<TIPO> temp);
	Coord<TIPO> operator*(Coord<TIPO> temp);
	Coord<TIPO> operator*(double k);
	Coord<TIPO> operator/(Coord<TIPO> tem);
	Coord<TIPO> operator/(double k);
};

typedef Coord<double> CoordD;
typedef Coord<float> CoordF;
typedef Coord<int> CoordI;
typedef Coord<unsigned int> CoordU;

template <typename TIPO>
Coord<TIPO>::Coord(TIPO x, TIPO y):x(x),y(y){}

template <typename TIPO>
Coord<TIPO>::Coord(){
	x=0;
	y=0;
}

template <typename TIPO>
Coord<TIPO>::~Coord(){}

template <typename TIPO>
TIPO Coord<TIPO>::getX(){
	return x;
}

template <typename TIPO>
TIPO Coord<TIPO>::getY(){
	return y;
}

template <typename TIPO>
void Coord<TIPO>::operator=(Coord<TIPO> temp){
	x=temp.x;
	y=temp.y;
}

template <typename TIPO>
void Coord<TIPO>::operator+=(Coord<TIPO> temp){
	x+=temp.x;
	y+=temp.y;
}

template <typename TIPO>
void Coord<TIPO>::operator-=(Coord<TIPO> temp){
	x-=temp.x;
	y-=temp.y;
}

template <typename TIPO>
void Coord<TIPO>::operator*=(double k){
	//vendo se o divisor nao e zero. 
	if(k == 0.0f){
		cout<< "Erro(dividindo por 0)" <<endl;
		exit(1);
	}
	x= k*x;
	y= k*y;
} 

template <typename TIPO>
void Coord<TIPO>::operator/=(double k){
	x= x/k;
	y= y/k;
}

template <typename TIPO>
Coord<TIPO> Coord<TIPO>::operator+(Coord<TIPO> temp){
	return Coord<TIPO>(x+temp.x,y+temp.y);
}

template <typename TIPO>
Coord<TIPO> Coord<TIPO>::operator-(Coord<TIPO> temp){
	return Coord<TIPO>(x-temp.x,y-temp.y);
}

template <typename TIPO>
Coord<TIPO> Coord<TIPO>::operator*(Coord<TIPO> temp){
	return Coord<TIPO>(x*temp.x,y*temp.y);
}

template <typename TIPO>
Coord<TIPO> Coord<TIPO>::operator*(double k){
	return Coord<TIPO>(k*x,k*y);
}

template <typename TIPO>
Coord<TIPO> Coord<TIPO>::operator/(Coord<TIPO> temp){
	//vendo se nenhuma das coordenas que vai dividir e zero
	if(temp.x == 0.0f || temp.Y == 0.0f){
		cout << "Erro(dividindo por 0)" << endl;	
		exit(1);
	}
	return Coord<TIPO>(x/temp.x,y/temp.y);
}

template <typename TIPO>
Coord<TIPO> Coord<TIPO>::operator/(double k){
	//vendo se o divisor nao e zero
	if(k == 0.0f){
		cout<< "Erro(dividindo por 0)" <<endl;
 		exit(1);
	}
	return Coord<TIPO>(x/k, y/k);
}


	
