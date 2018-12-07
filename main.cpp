#include "Headers.h"
#define ventanax 640
#define ventanay 640
#define tamper 30.0
#define velperso 5
//g++ main.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system Enemy.cpp Bala.cpp Personaje.cpp

using namespace std; using namespace sf;

void cerrarjuego(RenderWindow &windowexample){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        windowexample.close();   
    }
}

void animacionfondo(RenderWindow &windowexample ,RectangleShape &dibujo,int &colordibujo,int &auxiliar){
    colordibujo=colordibujo+auxiliar;
    if(colordibujo>254 || colordibujo<1)auxiliar=-1*auxiliar;             //
    dibujo.setFillColor(sf::Color(0,153,colordibujo,255));    
    windowexample.draw(dibujo);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(ventanax, ventanay), "Game");
    sf::RectangleShape fondo(sf::Vector2f(ventanax,ventanay));
    window.setVerticalSyncEnabled(1);
    //texto
    Font fuente;
    fuente.loadFromFile("Texto/texto.ttf");
    Text texto;
    sf::String cadena="puntuacion 0";
    texto.setString(cadena);
    texto.setFont(fuente);
    texto.setCharacterSize(20);
    texto.setPosition(100,20);
    //auxiliares
    int colorg=0,fondoaux=1;
    int contadorbalas=0,kills=0;
    int aux=0,a=0;
    bool boolbala=1,muerte=1;
    int numb=10,nume=50;
    string cadaux;
	srand(time(NULL));
    Enemy *enemy=new Enemy[nume];     //Inicializamos las clases enemy y Bala
    Bala *bala=new Bala[numb];   // lo de arriba 7u7
    Personaje personaje(ventanax/2-tamper/2,ventanay/2-tamper/2,tamper,tamper);
    while (window.isOpen()&&muerte){
        window.clear();
        cerrarjuego(window);    //lo de arriba
        animacionfondo(window,fondo,colorg,fondoaux);
        personaje.Movimiento();
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
                bala[contadorbalas].PosicionPer(
                    personaje.Per.getPosition().x , personaje.Per.getPosition().y,tamper,personaje.getDir());
                contadorbalas+=1;
                contadorbalas%=numb;
                boolbala=0;
                //cout<<"--";
            }
        }
        else {
            boolbala=1;
            //cout<<"|"<<contadorbalas<<"|";
        }
        for(int i=0;i<numb;i++){
            for(int j=0;j<nume;j++){
                if(bala[i].Colision(enemy[j].x,enemy[j].y,tamper)){
                enemy[j].Reposicionar(rand()%2*640-30,rand()%2*640-30);
                kills=kills + 1;
                }
            }
            if(bala[i].Colision(-120,-120,760))
            bala[i].Movimiento();
        window.draw((bala[i].bala));
        }
        string ab="Puntuacion "+to_string (kills);
        texto.setString(ab);
        //cout<<ab;
        //std::cout<<personaje.Per.getPosition().y<<" :: "<<personaje.Per.getPosition().x<<" :: "<<dir<<"\r"<<flush;
        window.display();
    }
    sf::Texture tmuerte;
    tmuerte.loadFromFile("explosion.png");
    sf::IntRect rectSourceSprite(30, 0, 30, 30);
    sf::Sprite sprite(tmuerte,rectSourceSprite);
    sprite.scale(Vector2f(1.5,1.5));
    sf::Clock clock;
    sprite.setPosition(Vector2f(personaje.x-personaje.tamx/4,personaje.y-personaje.tamy/4));
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
    string mensaje_final=("    You Died\nPuntuacion "+to_string(kills));
    texto.setString(mensaje_final);
    //texto.setCharacterSize(20);
    //texto.setFont(fuente);
    texto.setPosition((ventanax-70)/2,(ventanay-30)/2);
    texto.setFillColor(sf::Color(200,0,0));
    while(time++<200){
        window.clear();
        window.draw(fondo);
        window.draw(texto);
        window.display();
    }
    window.close();
    return 0;
} 
