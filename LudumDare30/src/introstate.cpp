#include "introstate.h"
#include <SFML/Window.hpp>
#include <iostream>

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL) _instance = new IntroState();
	return _instance;
}

void IntroState::init(){
    //Font errorproofing
    if(!_font.loadFromFile("res/dungeon.ttf"))
        std::cout << "res/dungeon.ttf not loaded." << std::endl;

    _msg.setFont(_font);
    _msg.setString("Untitled game");
    _msg.setCharacterSize(40);
    _msg.setColor(sf::Color(255, 255, 255));
    _msg.setPosition(640/2-80,10);
}
void IntroState::cleanup(){

}

void IntroState::handle_events(GameEngine* game, sf::Event event){
    _input.update(event);

    if(_input.key_pressed(sf::Keyboard::Return))
        std::cout << "Return worked" << std::endl;

    if(_input.key_pressed(sf::Keyboard::Up) 
        || _input.key_pressed(sf::Keyboard::W))
        std::cout << "Up worked" << std::endl;

    if(_input.key_pressed(sf::Keyboard::Down)
        || _input.key_pressed(sf::Keyboard::S))
        std::cout << "Down worked" << std::endl;

    // switch(event.type)
    // {
    //     case sf::Event::KeyPressed:
    //         if(event.key.code == sf::Keyboard::Return){
    //             std::cout << "Return worked" << std::endl;
    //         }
    //         else if(event.key.code == sf::Keyboard::Up
    //             || event.key.code == sf::Keyboard::W){
    //             //- Move menu cursor up
    //         }
    //         else if(event.key.code == sf::Keyboard::Down
    //             || event.key.code == sf::Keyboard::S){
    //             //- Move menu cursor down
    //         }
    //         break;
    //     default:
    //         break;
    // }
}
void IntroState::update(GameEngine* game){

}
void IntroState::draw(GameEngine* game){
    game->get_window()->draw(_msg);
}

void IntroState::pause(){

}
void IntroState::resume(){

}
