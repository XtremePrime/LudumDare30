#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(300,300), "Untitled game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
    	sf::Event event;
    	while(window.pollEvent(event))
    	{
    		switch(event.type)
    		{
    			case sf::Event::Closed:
    				window.close();
    				break;
    		}
    	}

    	window.display();
    	window.clear();
    }

    return 0;
}
