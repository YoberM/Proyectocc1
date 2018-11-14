#include <iostream>
#include "Enemy.h"
#include <math.h>
#define tamenemy 30
#define velenemy 0.70


Enemy::Enemy(){
	srand(time(NULL));
	int a=rand()%2,b=rand()%2;
	entidad.setPosition(sf::Vector2f(a*640-tamenemy*!a,b*640-tamenemy*!b));
	x=a*640-tamenemy*!a;
	y=b*640-tamenemy*!b;
	entidad.setSize(sf::Vector2f(tamenemy,tamenemy));
    texturaenemy.loadFromFile("Mina.png");
    entidad.setTexture(&texturaenemy,1);
    std::cout<<"|"<<a<<":"<<b<<"|";
}


Enemy::Enemy(float _x,float _y){
	x=_x;
	y=_y;
	entidad.setSize(sf::Vector2f(tamenemy,tamenemy));
    texturaenemy.loadFromFile("Mina.png");
    entidad.setTexture(&texturaenemy,1);
}

bool Enemy::Colision(float tamper){
    float x=tamenemy/2;
    float y=tamenemy/2;
    float px=tamper/2;
    float py=tamper/2;
	float re=tamenemy/2;
	float rp=tamper/2;
	float dx=fabs(x-px);
	float dy=fabs(y-py);
	std::cout<<re<<":"<<rp<<"::::"<<dx<<":"<<dy;
	if((dx-(re-rp)) && (dy-(re-rp))>=0) return 0;
	else return 1;
}


void Enemy::Movimiento(){
	std::cout<<"1 ";
	float ax,ay;
	if(!Colision(30)){
	if(px-x>0)ax=velenemy;else ax=-velenemy;
	if(py-y>0)ay=velenemy;else ay=-velenemy;
    entidad.move(sf::Vector2f(ax,ay));
    std::cout<<"X("<<entidad.getPosition().x<<" "<<entidad.getPosition().y<<") ";
    x+=ax;y+=ay;
    }
}

void Enemy::PosicionPer(float ex,float ey){
	std::cout<<" 2 ";
	px=ex;
	py=ey;
}
