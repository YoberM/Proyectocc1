#include <iostream>
#include "Bala.h"
#include <SFML/Graphics.hpp>
#define tambala 5
#define velbala 10

Bala::Bala(){
	x=0; y=0;
	bala.setSize(sf::Vector2f(tambala,tambala));
    bala.setFillColor(sf::Color::Red);
}

Bala::Bala(float _x=0, float _y=0){
	x=_x; y=_y;
	bala.setSize(sf::Vector2f(tambala,tambala));
    bala.setFillColor(sf::Color::Red);
}

void Bala::Movimiento(){
	if(direccion=='A')bala.move(sf::Vector2f(-velbala,0));
	if(direccion=='D')bala.move(sf::Vector2f(velbala,0));
	if(direccion=='W')bala.move(sf::Vector2f(0,-velbala));
	if(direccion=='S')bala.move(sf::Vector2f(0,velbala));
    std::cout<<"(:"<<int(bala.getPosition().x)<<"::"<<int(bala.getPosition().y)<<":) ";

}

void Bala::PosicionPer(float ex,float ey,float tam,char dir){
	direccion=dir;
	std::cout<<" 3 ";
	x=ex+tam/2;
	y=ey+tam/2;
	bala.setPosition(x,y);
}

