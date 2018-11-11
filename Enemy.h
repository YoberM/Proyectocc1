#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
class Enemy{
	float x,y,px,py;
public:
    sf::RectangleShape entidad;
	sf::Texture texturaenemy;
	Enemy(float ,float );
	Enemy();
	void Movimiento();
	void PosicionPer(float , float);//Posicion del personaje no del enemigo
};
#endif 