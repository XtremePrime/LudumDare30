#include <SFML/Graphics.hpp>

#include "gameengine.h"

using namespace std;

void GameEngine::init(){
    _window.create(sf::VideoMode(300,300), "Untitled game", sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(60);
}
void GameEngine::cleanup(){
	_window.close();
}

void GameEngine::handle_events(){
	_state_stack.back()->handle_events();
}
void GameEngine::update(){
	_state_stack.back()->update();
}
void GameEngine::draw(){
	_state_stack.back()->draw();
}

void GameEngine::change_state(State* state){
	//- Cleanup the current state
	if ( !_state_stack.empty() ) {
		_state_stack.back()->Cleanup();
		_state_stack.pop_back();
	}

	//- Store and init the new state
	_state_stack.push_back(state);
	_state_stack.back()->Init();
}
void GameEngine::push_state(State* state){
	//- Pause current state
	if ( !_state_stack.empty() ) {
		_state_stack.back()->Pause();
	}

	//- Store and init the new state
	_state_stack.push_back(state);
	_state_stack.back()->Init();
}
void GameEngine::pop_state(){
	//- Cleanup the current state
	if ( !_state_stack.empty() ) {
		_state_stack.back()->Cleanup();
		_state_stack.pop_back();
	}

	//- Resume previous state
	if ( !_state_stack.empty() ) {
		_state_stack.back()->Resume();
	}
}
