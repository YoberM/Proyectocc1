#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#define ventanax 640
#define ventanay 640
#define tamper 40 
int main()
{
    sf::RenderWindow window(sf::VideoMode(ventanax, ventanay), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(tamper,tamper));
    sf::CircleShape ward(2.f);
    ward.setFillColor(sf::Color::Red);
        sf::Texture texturas;
        texturas.loadFromFile("pokeball.png");
        shape.setTexture(&texturas,1);
        int acum=0;
        int aux=1;
    char dir='W';
     while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //ultimo avance*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) || aux>0){
            Enemy a1;
            aux*=-1;
            a1.Movimiento();
        }
        window.clear();
        window.draw(shape);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& shape.getPosition().x<=ventanax-tamper){
            shape.move(sf::Vector2f(0.1,0));
            dir='D';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& shape.getPosition().x>=0){
            shape.move(sf::Vector2f(-0.1,0));
            dir='A';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shape.getPosition().y>=0){
            shape.move(sf::Vector2f(0,-0.1));
            dir='W';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y<=ventanay-tamper){
            shape.move(sf::Vector2f(0,0.1));
            dir='S';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) return 0;
        std::cout<<shape.getPosition().y<<" :: "<<shape.getPosition().x<<" :: "<<dir<<std::endl;
        window.display();
    }
     return 0;
} 