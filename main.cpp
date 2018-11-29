#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Headers.h"
#define ventanax 640
#define ventanay 640
#define tamper 30.0
#define velperso 5
//g++ main.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system Enemy.cpp Bala.cpp Personaje.cpp

using namespace std; using namespace sf;
void Boton(sf::Keyboard X){

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(ventanax, ventanay), "Game");
    sf::RectangleShape fondo(sf::Vector2f(ventanax,ventanay));
    window.setVerticalSyncEnabled(1);
    window.setFramerateLimit(60);
    //texto
    fondo.setFillColor(sf::Color(40,55,71,255));
    Font fuente;
    fuente.loadFromFile("Texto/texto.ttf");
    Text texto;
    sf::String cadena="puntuacion 000";
    texto.setString(cadena);
    texto.setFont(fuente);
    texto.setCharacterSize(20);
    texto.setPosition(100,20);
    //auxiliares
    int colorg=0,aux3=1,contadorbalas=0,asesinato=0;
    int aux=0,a=0;
    bool boolbala=1,muerte=1;
    char dir='W';
    int numb=10,nume=10;
    string cadaux;
	srand(time(NULL));
    Enemy *enemy=new Enemy[nume];     //Inicializamos las clases enemy y Bala
    Bala *bala=new Bala[numb];   // lo de arriba 7u7
    Personaje personaje(0,0,tamper,tamper);
    while (window.isOpen()&&muerte){
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
        window.draw(texto);
        window.draw(personaje.Per);
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                delete[] enemy;
                delete[] bala;
            }
        }
        
        //Activar enemigos
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))aux=1;
            if(aux){
                for(int i=0;i<a++/300 && i<nume;i++){
                    enemy[i].PosicionPer(personaje.Per.getPosition().x,personaje.Per.getPosition().y);
                    if(!enemy[i].Colision(tamper))
                    enemy[i].Movimiento();
                    else muerte=0;
                    window.draw((enemy[i].entidad));
                }
            }


        //Bala
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))muerte=!muerte;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            if(boolbala==1){
                bala[contadorbalas].PosicionPer(personaje.Per.getPosition().x , personaje.Per.getPosition().y,tamper,dir);
                contadorbalas+=1;
                contadorbalas%=numb;
                boolbala=0;
                cout<<"--";
            }
        }
        else {
            boolbala=1;
            cout<<"|"<<contadorbalas<<"|";
        }
        for(int i=0;i<numb;i++){
            for(int j=0;j<nume;j++){
                if(bala[i].Colision(enemy[j].x,enemy[j].y,tamper)){
                enemy[j].Reposicionar(rand()%2*640-30,rand()%2*640-30);
                asesinato+=1;
                }
            }
            if(bala[i].Colision(0,0,760))
            bala[i].Movimiento();
        window.draw((bala[i].bala));
        }
        string ab="Puntuacion";
        ab.push_back(asesinato);

        texto.setString(ab);
        cout<<ab;
        std::cout<<personaje.Per.getPosition().y<<" :: "<<personaje.Per.getPosition().x<<" :: "<<dir<<std::endl;
        window.display();
    }

  sf::Event event;
        sf::Texture tmuerte;
        tmuerte.loadFromFile("explosion3.png");
        sf::IntRect rectSourceSprite(30, 0, 30, 30);
        sf::Sprite sprite(tmuerte,rectSourceSprite);
        sf::Clock clock;
        sprite.setPosition(Vector2f(personaje.x,personaje.y));
    while(!muerte){
        if (clock.getElapsedTime().asSeconds() > 0.5f){
          if (rectSourceSprite.left >= 120)
            muerte=1;
          else
            rectSourceSprite.left += 30;
          sprite.setTextureRect(rectSourceSprite);
          clock.restart();
        }
        //window.clear();
        window.draw(sprite);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            delete[] enemy;
            delete[] bala;
            return 0;
        }
        window.display();
    }
    int time=0;
    while(time>1000){
        window.display();
    }
    window.close();
    return 0;
} 
