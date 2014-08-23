#include "introstate.h"
#include <SFML/Window.hpp>

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL) _instance = new IntroState();
	return _instance;
}

void IntroState::init(){

}
void IntroState::cleanup(){

}

void IntroState::handle_events(GameEngine* game, sf::Event event){
    switch(event.type)
    {
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Return){
                //- Enter menu option
            }
            else if(event.key.code == sf::Keyboard::Up
                || event.key.code == sf::Keyboard::W){
                //- Move menu cursor up
            }
            else if(event.key.code == sf::Keyboard::Down
                || event.key.code == sf::Keyboard::S){
                //- Move menu cursor down
            }
            break;
        default:
            break;
    }
}
void IntroState::update(GameEngine* game){

}
void IntroState::draw(GameEngine* game){

}

void IntroState::pause(){

}
void IntroState::resume(){

}
