#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameengine.h"
#include "states/introstate.h"

int main()
{
    GameEngine game;
    game.init();

    game.change_state(IntroState::instance());


    sf::Clock clock;

    while(game.is_running()){
        sf::Time deltaTime = clock.restart();

        game.handle_events();
        game.update(deltaTime);
        game.draw();
    }
    game.cleanup();
    // while(window.isOpen())
    // {
    // 	sf::Event event;
    // 	while(window.pollEvent(event))
    // 	{
    // 		switch(event.type)
    // 		{
    // 			case sf::Event::Closed:
    // 				window.close();
    // 				break;
    // 		}
    // 	}
    // 	window.draw();
    // 	window.clear();
    // }

    return 0;
}
