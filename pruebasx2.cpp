#include <SFML/Graphics.hpp>
#include <iostream>
 int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(20,20));
    shape.setFillColor(sf::Color::Blue);
    sf::CircleShape ward(2.f);
    ward.setFillColor(sf::Color::Red);
    int acum=0,aux=1;
     while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        	ward.setPosition(shape.getPosition().x,shape.getPosition().y);
            acum=3000;
            window.draw(ward);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& shape.getPosition().x<=620){
        	shape.move(sf::Vector2f(0.1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& shape.getPosition().x>=0){
        	shape.move(sf::Vector2f(-0.1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shape.getPosition().y>=0){
        	shape.move(sf::Vector2f(0,-0.1));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y<=460){
        	shape.move(sf::Vector2f(0,0.1));
        }
        if(shape.getPosition().y<=460 || acum>=0){
            if(acum-->0)
                shape.move(sf::Vector2f(0,-0.05));
            else
                shape.move(sf::Vector2f(0,0.05));
        }
        std::cout<<shape.getPosition().y<<" :: "<<shape.getPosition().x<<" :: "<<acum<<std::endl;
        window.display();
    }
     return 0;
} 