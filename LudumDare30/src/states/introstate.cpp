#include "introstate.h"
#include "gamestate.h"
#include "../resourcemanager.h"
#include <SFML/Window.hpp>
#include <iostream>

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL) _instance = new IntroState();
	return _instance;
}

void IntroState::init(){
    //Font errorproofing
    // if(!_font.loadFromFile("res/dungeon.ttf"))
    //     std::cout << "res/dungeon.ttf not loaded." << std::endl;
    _font = *ResourceManager::instance()->get_font("dungeon");

    //Design and Selector
    _selector.setRadius(10.f);
    _selector.setPosition(20, 110);
    _selector.setFillColor(sf::Color(255,255,255));

    _title.setFont(_font);
    _start.setFont(_font);
    _quit.setFont(_font);

    _title.setString("Untitled game");
    _start.setString("Start Game");
    _quit.setString("Quit Game");

    _title.setCharacterSize(40);
    _start.setCharacterSize(30);
    _quit.setCharacterSize(30);

    _title.setColor(sf::Color(255,255,255));
    _start.setColor(sf::Color(255,255,255));
    _quit.setColor(sf::Color(255,255,255));

    _title.setPosition(GameEngine::GAME_WIDTH/2-100, 10);
    _start.setPosition(50, 100);
    _quit.setPosition(50, 150);

    //Audio management
    sf::SoundBuffer buffer;
    buffer.loadFromFile("res/sfx/Button_Up.wav");   _btn_up.setBuffer(buffer);
    buffer.loadFromFile("res/sfx/Button_Down.wav"); _btn_down.setBuffer(buffer);

    // if(!buffer.loadFromFile("res/sfx/Button_Up.wav"))
    //     std::cout << "res/sfx/Button_Up.wav" << std::endl;

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
                game->push_state(GameState::instance());
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

        move_selector(_menu_item);
        _btn_up.play();
    }
    if(_input.key_pressed(sf::Keyboard::Down) || _input.key_pressed(sf::Keyboard::S))
    {
        _menu_item--;
        if(_menu_item < 0) _menu_item = _TOTAL_MENU_ITEMS;

        move_selector(_menu_item);
        _btn_down.play();
    }

    std::cout << _menu_item << " ";
}
void IntroState::update(GameEngine* game, sf::Time deltaTime){

}
void IntroState::draw(GameEngine* game){
    game->get_window()->draw(_title);
    game->get_window()->draw(_start);
    game->get_window()->draw(_quit);

    game->get_window()->draw(_selector);
}

void IntroState::pause(){

}
void IntroState::resume(){

}

void IntroState::move_selector(int idx)
{
    switch(idx)
    {
        case 0:
        {
            _selector.setPosition(20, 110);
            break;
        }
        case 1:
        {
            _selector.setPosition(20, 160);
            break;
        }
    }
}
