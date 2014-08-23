#include "introstate.h"

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL) _instance = new IntroState();
	return _instance;
}

void IntroState::init(){

}
void IntroState::cleanup(){

}

void IntroState::handle_events(GameEngine* game){

}
void IntroState::update(GameEngine* game){

}
void IntroState::draw(GameEngine* game){

}

void IntroState::pause(){

}
void IntroState::resume(){

}
