#include "gamestate.h"
#include "../tiles/grasstile.h"
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

GameState* GameState::_instance;

GameState* GameState::instance(){
	if(_instance == NULL) _instance = new GameState();
	return _instance;
}

void GameState::init(){
    //Font errorproofing
    // if(!_font.loadFromFile("res/dungeon.ttf"))
    //     std::cout << "res/dungeon.ttf not loaded." << std::endl;
    ResourceManager* res = ResourceManager::instance();
    _font = *res->get_font("dungeon");

    _map.register_type(new GrassTileType());
    _map.generate_map("map1");
}
void GameState::cleanup(){

}

void GameState::handle_events(GameEngine* game, sf::Event event){
    _input.update(event);
    _player.handle_events(_input);

    //if(_input.key_pressed(sf::Keyboard::Up) || _input.key_pressed(sf::Keyboard::W))
    //{
    //    _menu_item++;
    //    if(_menu_item > _TOTAL_MENU_ITEMS) _menu_item = 0;
    //}
    //if(_input.key_pressed(sf::Keyboard::Down) || _input.key_pressed(sf::Keyboard::S))
    //{
    //    _menu_item--;
    //    if(_menu_item < 0) _menu_item = _TOTAL_MENU_ITEMS;
    //}
}
void GameState::update(GameEngine* game, sf::Time delta){
    _player.update(delta);
}
void GameState::draw(GameEngine* game){
    _player.draw(game->get_window());
    _map.draw(game->get_window());
}

void GameState::pause(){

}
void GameState::resume(){

}
