#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>
#include "Personaje.h"
class Bala{
	float x,y;
	char direccion;
public:
    sf::RectangleShape bala;
	Bala();
	Bala(float,float);
	bool Colision(float,float,float);
	void Movimiento();
	void PosicionPer(float,float,float,char);
};
#endif 