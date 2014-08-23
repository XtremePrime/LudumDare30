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
    _msg.setPosition(GameEngine::GAME_WIDTH/2-100, 10);
}
void IntroState::cleanup(){

}

void IntroState::handle_events(GameEngine* game, sf::Event event){
    _input.update(event);

    if(_input.key_pressed(sf::Keyboard::Return))
    {
        switch(_menu_item)
        {
            case 0: // Start Game
            {
                break;
            }
            case 1: // Quit game
            {
                game->quit();
                break;
            }   
        }
    }

    if(_input.key_pressed(sf::Keyboard::Up) || _input.key_pressed(sf::Keyboard::W))
    {
        _menu_item++;
        if(_menu_item > _TOTAL_MENU_ITEMS) _menu_item = 0;
    }
    if(_input.key_pressed(sf::Keyboard::Down) || _input.key_pressed(sf::Keyboard::S))
    {
        _menu_item--;
        if(_menu_item < 0) _menu_item = _TOTAL_MENU_ITEMS;
    }

    std::cout << _menu_item << " ";
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
