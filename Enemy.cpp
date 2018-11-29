#include <iostream>
#include "Enemy.h"
#include <math.h>
#define tamenemy 30
#define velenemy 0.70


Enemy::Enemy()
{
	int a=rand()%2,b=rand()%2;
	entidad.setPosition(sf::Vector2f(a*640-tamenemy*!a,b*640-tamenemy*!b));
	x=a*640-tamenemy*!a;
	y=b*640-tamenemy*!b;
	entidad.setSize(sf::Vector2f(tamenemy,tamenemy));
    texturaenemy.loadFromFile("Mina.png");
    entidad.setTexture(&texturaenemy,1);
    std::cout<<"|"<<a<<":"<<b<<"|";
}

bool Enemy::Colision(float tamper){
	if(x<=px+tamper &&
	   x>=px && y>=py &&
	   y<=py+tamper)return 1;
	if(x+tamenemy<=px+tamper &&
	   x+tamenemy>=px && y>=py &&
	   y<py+tamper) return 1;
	if(x<=px+tamper &&
	   x>=px && y+tamenemy>=py &&
	   y+tamenemy<=py+tamper)return 1;
	if(x+tamenemy<=px+tamper &&
	   x+tamenemy>=px && y+tamenemy>=py &&
	   y+tamenemy<=py+tamper)return 1;
	return 0;
}

Enemy::Enemy(float _x,float _y){
	x=_x;
	y=_y;
	entidad.setSize(sf::Vector2f(tamenemy,tamenemy));
    texturaenemy.loadFromFile("Mina.png");
    entidad.setTexture(&texturaenemy,1);
}

void Enemy::Reposicionar(float nx,float ny){
	x=nx;
	y=ny;
	entidad.setPosition(sf::Vector2f(x,y));
}

void Enemy::Movimiento(){
	std::cout<<"1";
	float ax,ay;
	//if(!Colision(30)){
	if(px-x>0)ax=velenemy;else ax=-velenemy;
	if(py-y>0)ay=velenemy;else ay=-velenemy;
    entidad.move(sf::Vector2f(ax,ay));
    std::cout<<"("<<entidad.getPosition().x<<","<<entidad.getPosition().y<<")";
    x+=ax;y+=ay;
	//}
}

void Enemy::PosicionPer(float ex,float ey){
	std::cout<<" 2 ";
	px=ex;
	py=ey;
}


