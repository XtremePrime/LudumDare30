#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(300,300), "Untitled game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    return 0;
}
