#ifndef STATE_H
#define STATE_H
#include <vector>
#include "gameengine.h"
#include <SFML/Window.hpp>

class State {
private:
public:
	virtual void init() = 0;
	virtual void cleanup() = 0;

	virtual void handle_events(GameEngine* game) = 0;
	virtual void update(GameEngine* game) = 0;
	virtual void draw(GameEngine* game) = 0;

 	virtual void pause() = 0;
 	virtual void resume() = 0;

	void change_state(GameEngine* game, State* state){
		game->change_state(state);
	}
	virtual ~State() = 0;
protected:
    State(){}
};
inline State::~State(){}
#endif // STATE_H
