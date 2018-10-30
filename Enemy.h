#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
class Enemy{
	float x,y,px,py;
public:
    sf::RectangleShape entidad;
	Enemy();
	Enemy(float ,float );
	void Movimiento();
	void PosicionPer(float , float);//Posicion del personaje no del enemigo
};
#endif 