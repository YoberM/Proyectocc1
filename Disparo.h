#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/Graphics.hpp>
class Disparo{
	float x,y;
	char direccion;
public:
    sf::RectangleShape bala;
	Disparo();
	void Movimiento(char);
	void PosicionPer(float,float,float);
};
#endif 