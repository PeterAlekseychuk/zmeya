#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
sf::CircleShape hero(40.f);
int speed = 1;
void keyboard();
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(900, 480), "ZMEYKA!");
	//sf::CircleShape hero(40.f);
	hero.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		keyboard();

		

		window.clear();
		window.draw(hero);
		window.display();
		
	}
	
		
	return 0;
}
void keyboard() {


	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		hero.move(1, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		hero.move(-1, 0);
	}if (Keyboard::isKeyPressed(Keyboard::W))

	{
		hero.move(0, -speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		hero.move(0, speed);
	}
}