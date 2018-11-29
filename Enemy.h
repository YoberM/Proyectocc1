#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "Entidad.h"
class Enemy : public Entidad
{
public:
	float x,y,px,py;
    sf::RectangleShape entidad;
	sf::Texture texturaenemy;
	Enemy(float ,float );
	Enemy();
	void Reposicionar(float,float);
	void Movimiento();
	void PosicionPer(float , float);//Posicion del personaje no del enemigo
	bool Colision(float);
};
#endif 