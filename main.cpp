#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"
#include "Bala.h"
#include "Personaje.h"
#include "Colision.h"
#define ventanax 640
#define ventanay 640
#define tamper 30.0
#define velperso 5
//g++ main.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system Enemy.cpp Bala.cpp Personaje.cpp

void Boton(sf::Keyboard X){

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(ventanax, ventanay), "Game");
    sf::RectangleShape fondo(sf::Vector2f(ventanax,ventanay));
    window.setVerticalSyncEnabled(1);
    window.setFramerateLimit(60);
    fondo.setFillColor(sf::Color(40,55,71,255));
    int colorg=0,aux3=1;
    int aux=0,a=0;
    bool aux2=1;
    char dir='W';
    int numb=5,nume=4;
	srand(time(NULL));
    Enemy *enemy=new Enemy[nume];     //Inicializamos las clases enemy y Bala
    for(int i=0;i<nume;i++){

    }
    Bala *bala=new Bala[5];   // lo de arriba 7u7
    Personaje personaje(0,0,tamper,tamper);
     while (window.isOpen()){
        window.clear();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            delete[] enemy;
            delete[] bala;
            return 0;
        }
        window.draw(fondo);
        colorg=colorg+aux3;std::cout<<colorg;               //estetica , darle color al fondo nomas xd
        if(colorg>254 || colorg<1)aux3=-1*aux3;             //
        fondo.setFillColor(sf::Color(0,153,colorg,255));    //lo de arriba
        dir=personaje.Movimiento();
        window.draw(personaje.Per);
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                delete[] enemy;
                delete[] bala;
                window.close();
            }
        }
        
        //Activar enemigos
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))aux=1;
            if(aux){
                for(int i=0;i<a++/300 && i<4;i++){
                    enemy[i].PosicionPer(personaje.Per.getPosition().x,personaje.Per.getPosition().y);
                    enemy[i].Movimiento();
                    window.draw((enemy[i].entidad));
                }
            }


        //Bala
        aux2=0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)||aux2==1){
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::F) || aux2==0){
                bala[0].PosicionPer(personaje.Per.getPosition().x , personaje.Per.getPosition().y,tamper,dir);
                window.draw((bala[0].bala));
            }
            else    {
                aux2=0;
            }
            aux2=1;
        }
        else {
            bala[0].Movimiento();
            window.draw((bala[0].bala));
        }
        
        std::cout<<personaje.Per.getPosition().y<<" :: "<<personaje.Per.getPosition().x<<" :: "<<dir<<std::endl;
        window.display();
    }
     return 0;
} 
