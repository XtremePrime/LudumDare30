#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "state.h"

class IntroState : public State{
private:
	static IntroState* _instance;
public:
	static IntroState* instance();
    ~IntroState(){
    	
    }

	virtual void init();
	virtual void cleanup();

	virtual void handle_events(GameEngine* game);
	virtual void update(GameEngine* game);
	virtual void draw(GameEngine* game);

 	virtual void pause();
 	virtual void resume();
};

#endif // INTROSTATE_H
