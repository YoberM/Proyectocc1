#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/Graphics.hpp>
class Disparo{
	float x,y;
	char direccion;
public:
    sf::RectangleShape bala;
	Disparo(float,float);
	void Movimiento();
	void PosicionPer(float,float,float,char);
};
#endif 