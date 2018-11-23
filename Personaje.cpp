#include <iostream>
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#define ventanax 640
#define ventanay 640
#define velperso 5
Personaje::Personaje(float px=0,float py=0,float tampx=0,float tampy=0){
	x=px; y=py;
	tamx=tampx; tamy=tampy;
	texturasPer[0].loadFromFile("NaveW.png");
	texturasPer[1].loadFromFile("NaveA.png");
	texturasPer[2].loadFromFile("NaveS.png");
	texturasPer[3].loadFromFile("NaveD.png");
	Per.setSize(sf::Vector2f(tamx,tamy));
	Per.setPosition(x,y);
    Per.setTexture(&texturasPer[0],1);
}

char Personaje::Movimiento(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& Per.getPosition().x<ventanax-tamx){
        Per.move(sf::Vector2f(velperso,0));
        Per.setTexture(&texturasPer[3],1);
        x+=velperso;
        dir='D';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& Per.getPosition().x>0){
        Per.move(sf::Vector2f(-velperso,0));
        Per.setTexture(&texturasPer[1],1);
        x-=velperso;
        dir='A';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Per.getPosition().y>0){
        Per.move(sf::Vector2f(0,-velperso));
        Per.setTexture(&texturasPer[0],1);
        y-=velperso;
        dir='W';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Per.getPosition().y<ventanay-tamy){
        Per.move(sf::Vector2f(0,velperso));
        Per.setTexture(&texturasPer[2],1);
        y+=velperso;
        dir='S';
    } 
    return dir;
}

void Disparo(){

}