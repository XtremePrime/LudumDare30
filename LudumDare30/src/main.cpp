#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameengine.h"

int main()
{
    GameEngine game;
    game.init();

    game.ChangeState(IntroState::instance());

    while(game.running()){
        game.handle_events();
        game.update();
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
