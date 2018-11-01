#include <iostream>
#include "Disparo.h"
#include <SFML/Graphics.hpp>
#define tambala 5
#define velbala 0.5

Disparo::Disparo(){
	x=0; y=0;
	bala.setSize(sf::Vector2f(tambala,tambala));
    bala.setFillColor(sf::Color::Red);
}

void Disparo::Movimiento(char dir){
	if(dir=='A')bala.move(sf::Vector2f(-velbala,0));
	if(dir=='D')bala.move(sf::Vector2f(velbala,0));
	if(dir=='W')bala.move(sf::Vector2f(0,-velbala));
	if(dir=='S')bala.move(sf::Vector2f(0,velbala));
    std::cout<<"(-"<<bala.getPosition().x<<"-"<<bala.getPosition().y<<"-) ";

}

void Disparo::PosicionPer(float ex,float ey,float tam){
	std::cout<<" 3 ";
	x=ex+tam/2;
	y=ey+tam/2;
	bala.setPosition(x,y);
}

