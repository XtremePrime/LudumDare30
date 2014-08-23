#ifndef STATE_H
#define STATE_H
#include <vector>


class State {
private:
public:
	virtual void init() = 0;
	virtual void cleanup();
 
	virtual void handle_events(GameEngine* game) = 0;
	virtual void update(GameEngine* game) = 0;
	virtual void draw(GameEngine* game) = 0;
 	
 	virtual void pause() = 0;
 	virtual void resume() = 0;
 
	void change_state(GameEngine* game, State* state){
		game->change_state(state);
	}
protected:
	State(){}
};

#endif // STATE_H