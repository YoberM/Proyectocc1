#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
class Entidad{
public:
	virtual void Movimiento()=0;
	virtual void PosicionPer(float , float)=0;//Posicion del personaje no del enemigo
	virtual bool Colision(float)=0;
};
#endif 