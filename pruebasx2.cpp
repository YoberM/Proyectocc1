#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 450), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Blue);
    sf::CircleShape ward(2.f);
    ward.setFillColor(sf::Color::Red);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        	window.draw(ward);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        	shape.move(sf::Vector2f(0.1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        	shape.move(sf::Vector2f(-0.1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        	shape.move(sf::Vector2f(0,-0.1));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y<=400){
        	shape.move(sf::Vector2f(0,0.100));
        }
        std::cout<<shape.getPosition().y<<std::endl;
        window.display();
    }

    return 0;
}