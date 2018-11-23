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
using namespace std;
using namespace sf;
void Boton(sf::Keyboard X){

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(ventanax, ventanay), "Game");
    sf::RectangleShape fondo(sf::Vector2f(ventanax,ventanay));
    window.setVerticalSyncEnabled(1);
    window.setFramerateLimit(60);
    fondo.setFillColor(sf::Color(40,55,71,255));
    int colorg=0,aux3=1,contadorbalas=0;
    int aux=0,a=0;
    bool aux2=1;
    char dir='W';
    int numb=10,nume=10;
	srand(time(NULL));
    Enemy *enemy=new Enemy[nume];     //Inicializamos las clases enemy y Bala
    Bala *bala=new Bala[numb];   // lo de arriba 7u7
    Personaje personaje(0,0,tamper,tamper);
     while (window.isOpen()){
        window.clear();
        cout<<endl;
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
                for(int i=0;i<a++/300 && i<nume;i++){
                    enemy[i].PosicionPer(personaje.Per.getPosition().x,personaje.Per.getPosition().y);
                    if(!enemy[i].Colision(tamper))
                    enemy[i].Movimiento();
                    window.draw((enemy[i].entidad));
                }
            }


        //Bala
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            if(aux2==1){
                bala[contadorbalas].PosicionPer(personaje.Per.getPosition().x , personaje.Per.getPosition().y,tamper,dir);
                contadorbalas+=1;
                contadorbalas%=numb;
                aux2=0;
                cout<<"--";
            }
        }
        else {
            aux2=1;
            cout<<"|"<<contadorbalas<<"|";
        }
        for(int i=0;i<numb;i++){
            for(int j=0;j<nume;j++){
                if(bala[i].Colision(enemy[j].x,enemy[j].y,tamper))
                enemy[j].Reposicionar(rand()%2*640-30,rand()%2*640-30);
            }
            bala[i].Movimiento();
        window.draw((bala[i].bala));
        }
        std::cout<<personaje.Per.getPosition().y<<" :: "<<personaje.Per.getPosition().x<<" :: "<<dir<<std::endl;
        window.display();
    }
     return 0;
} 
