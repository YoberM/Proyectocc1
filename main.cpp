#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include "Disparo.h"
#define ventanax 640
#define ventanay 640
#define tamper 30 
#define velperso 5
//g++ main.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system Enemy.cpp Disparo.cpp

int main()
{
    sf::RenderWindow window(sf::VideoMode(ventanax, ventanay), "Game");
    sf::RectangleShape shape(sf::Vector2f(tamper,tamper));
    sf::RectangleShape fondo(sf::Vector2f(ventanax,ventanay));
    window.setVerticalSyncEnabled(1);
                        sf::CircleShape ward(2.f);//no sirve pero lo uso como ejemplo
    ward.setFillColor(sf::Color::Red);
    sf::Texture texturas;
    texturas.loadFromFile("Nave.png");
    fondo.setFillColor(sf::Color::Blue);
    shape.setTexture(&texturas,1);
    int acum=0;
    int aux=0;
    bool aux2=1;
    char dir='W';
    Enemy a1(0,0);     //Inicializamos las clases enemy y disparo
    Disparo d1(-10,-10);   // lo de arriba 7u7
     while (window.isOpen()){
        window.clear();
        window.draw(fondo);
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //ultimo avance*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) || aux>0){
            aux=1;
        }
        if(aux){
            a1.PosicionPer(shape.getPosition().x,shape.getPosition().y);
            a1.Movimiento();
            window.draw((a1.entidad));

        }
        window.draw(shape);
        //Movimiento del personaje
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& shape.getPosition().x<ventanax-tamper){
            shape.move(sf::Vector2f(velperso,0));
            texturas.loadFromFile("NaveD.png");
            shape.setTexture(&texturas,1);
            dir='D';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& shape.getPosition().x>0){
            shape.move(sf::Vector2f(-velperso,0));
            texturas.loadFromFile("NaveA.png");
            shape.setTexture(&texturas,1);
            dir='A';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shape.getPosition().y>0){
            shape.move(sf::Vector2f(0,-velperso));
            texturas.loadFromFile("NaveW.png");
            shape.setTexture(&texturas,1);
            dir='W';
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y<ventanay-tamper){
            shape.move(sf::Vector2f(0,velperso));
            texturas.loadFromFile("NaveS.png");
            shape.setTexture(&texturas,1);
            dir='S';
        } //Fin de movimiento del personaje

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) return 0;
        //Disparo
        aux2=0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)||aux2==1){
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F) || aux2==0){
                d1.PosicionPer(shape.getPosition().x , shape.getPosition().y,tamper,dir);
                window.draw((d1.bala));
            }
            else    {
                aux2=0;
            }
            aux2=1;
        }
        else {
            d1.Movimiento();
            window.draw((d1.bala));
        }
        
        std::cout<<shape.getPosition().y<<" :: "<<shape.getPosition().x<<" :: "<<dir<<std::endl;
        window.display();
    }
     return 0;
} 
