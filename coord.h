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
