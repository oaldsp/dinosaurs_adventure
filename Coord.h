#pragma once

#include <iostream>
using namespace std;

template <typename TYPE>//para tornar a funcao mais generica.
class Coord{
	private:
public:
	TYPE x;
	TYPE y;

	Coord(TYPE x,TYPE y);
	Coord();
	~Coord();
	
	const TYPE getX() const;
	const TYPE getY() const;

	//operadores para facilitar a utilizacao das coordenadas.
	//sem retorno.
	void operator=(Coord<TYPE> temp);
       	void operator+=(Coord<TYPE> temp);
	void operator-=(Coord<TYPE> temp);
	void operator*=(double k);
	void operator/=(double k);
	
	//com retorno coord.
	Coord<TYPE> operator+(Coord<TYPE> temp);
	Coord<TYPE> operator-(Coord<TYPE> temp);
	Coord<TYPE> operator*(Coord<TYPE> temp);
	Coord<TYPE> operator*(double k);
	Coord<TYPE> operator/(Coord<TYPE> tem);
	Coord<TYPE> operator/(double k);
};

typedef Coord<double> CoordD;
typedef Coord<float> CoordF;
typedef Coord<int> CoordI;
typedef Coord<unsigned int> CoordU;

template <typename TYPE>
Coord<TYPE>::Coord(TYPE x, TYPE y):x(x),y(y){}

template <typename TYPE>
Coord<TYPE>::Coord(){
	x=0;
	y=0;
}

template <typename TYPE>
Coord<TYPE>::~Coord(){}

template <typename TYPE>
const TYPE Coord<TYPE>::getX() const{
	return x;
}

template <typename TYPE>
const TYPE Coord<TYPE>::getY() const{
	return y;
}

template <typename TYPE>
void Coord<TYPE>::operator=(Coord<TYPE> temp){
	x=temp.x;
	y=temp.y;
}

template <typename TYPE>
void Coord<TYPE>::operator+=(Coord<TYPE> temp){
	x+=temp.x;
	y+=temp.y;
}

template <typename TYPE>
void Coord<TYPE>::operator-=(Coord<TYPE> temp){
	x-=temp.x;
	y-=temp.y;
}

template <typename TYPE>
void Coord<TYPE>::operator*=(double k){
	//vendo se o divisor nao e zero. 
	if(k == 0.0f){
		cout<< "Erro(dividindo por 0)" <<endl;
		exit(1);
	}
	x= k*x;
	y= k*y;
} 

template <typename TYPE>
void Coord<TYPE>::operator/=(double k){
	x= x/k;
	y= y/k;
}

template <typename TYPE>
Coord<TYPE> Coord<TYPE>::operator+(Coord<TYPE> temp){
	return Coord<TYPE>(x+temp.x,y+temp.y);
}

template <typename TYPE>
Coord<TYPE> Coord<TYPE>::operator-(Coord<TYPE> temp){
	return Coord<TYPE>(x-temp.x,y-temp.y);
}

template <typename TYPE>
Coord<TYPE> Coord<TYPE>::operator*(Coord<TYPE> temp){
	return Coord<TYPE>(x*temp.x,y*temp.y);
}

template <typename TYPE>
Coord<TYPE> Coord<TYPE>::operator*(double k){
	return Coord<TYPE>(k*x,k*y);
}

template <typename TYPE>
Coord<TYPE> Coord<TYPE>::operator/(Coord<TYPE> temp){
	//vendo se nenhuma das coordenas que vai dividir e zero
	if(temp.x == 0.0f || temp.Y == 0.0f){
		cout << "Erro(dividindo por 0)" << endl;	
		exit(1);
	}
	return Coord<TYPE>(x/temp.x,y/temp.y);
}

template <typename TYPE>
Coord<TYPE> Coord<TYPE>::operator/(double k){
	//vendo se o divisor nao e zero
	if(k == 0.0f){
		cout<< "Erro(dividindo por 0)" <<endl;
 		exit(1);
	}
	return Coord<TYPE>(x/k, y/k);
}
