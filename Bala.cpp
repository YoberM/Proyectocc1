#include <iostream>
#include "Bala.h"
#include <SFML/Graphics.hpp>
#define tambala 5
#define velbala 10

Bala::Bala(){
	x=-100; y=-100;
	bala.setSize(sf::Vector2f(tambala,tambala));
    bala.setFillColor(sf::Color(rand()%255,0,rand()%255,255));
	bala.setPosition(x,y);
}

Bala::Bala(float _x=0, float _y=0){
	x=_x; y=_y;
	bala.setSize(sf::Vector2f(tambala,tambala));
    bala.setFillColor(sf::Color::Red);
}

bool Bala::Colision(float px,float py,float tamper){
	if(x<=px+tamper &&
	   x>=px && y>=py &&
	   y<=py+tamper)return 1;
	if(x+tambala<=px+tamper &&
	   x+tambala>=px && y>=py &&
	   y<py+tamper) return 1;
	if(x<=px+tamper &&
	   x>=px && y+tambala>=py &&
	   y+tambala<=py+tamper)return 1;
	if(x+tambala<=px+tamper &&
	   x+tambala>=px && y+tambala>=py &&
	   y+tambala<=py+tamper)return 1;
	return 0;
}

void Bala::Movimiento(){
	if(direccion=='A'){bala.move(sf::Vector2f(-velbala,0));x+=-velbala;}
	if(direccion=='D'){bala.move(sf::Vector2f(velbala,0)); x+=velbala;}
	if(direccion=='W'){bala.move(sf::Vector2f(0,-velbala));y+=-velbala;}
	if(direccion=='S'){bala.move(sf::Vector2f(0,velbala)); y+=velbala;}
    //std::cout<<"b("<<int(bala.getPosition().x)<<","<<int(bala.getPosition().y)<<")";

}

void Bala::PosicionPer(float ex,float ey,float tam,char dir){
	direccion=dir;
	x=ex+tam/2-tambala/2;
	y=ey+tam/2-tambala/2;
	bala.setPosition(x,y);
}

