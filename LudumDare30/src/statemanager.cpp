

#include "statemanager.h"

using namespace std;

void GameEngine::init(){

}
void GameEngine::cleanup(){
	
}

void GameEngine::handle_events(){
	state_stack.back()->handle_events();
}
void GameEngine::update(){
	state_stack.back()->update();
}
void GameEngine::draw(){
	state_stack.back()->draw();
}

void GameEngine::change_state(State* state){
	// cleanup the current state
	if ( !state_stack.empty() ) {
		state_stack.back()->Cleanup();
		state_stack.pop_back();
	}

	// store and init the new state
	state_stack.push_back(state);
	state_stack.back()->Init();
}
void GameEngine::push_state(State* state){
	//- Pause current state
	if ( !state_stack.empty() ) {
		state_stack.back()->Pause();
	}

	//- Store and init the new state
	state_stack.push_back(state);
	state_stack.back()->Init();
}
void GameEngine::pop_state(){
	//- Cleanup the current state
	if ( !state_stack.empty() ) {
		state_stack.back()->Cleanup();
		state_stack.pop_back();
	}

	//- Resume previous state
	if ( !state_stack.empty() ) {
		state_stack.back()->Resume();
	}
}