#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "inputhandler.h"

class IntroState : public State{
private:
	static IntroState* _instance;
	InputHandler _input;

	short int _menu_item = 0; // 0 = top option
	const short int _TOTAL_MENU_ITEMS = 1;

	sf::Font _font;
	sf::Text _msg;

public:
	static IntroState* instance();
    ~IntroState(){

    }

	virtual void init();
	virtual void cleanup();

	virtual void handle_events(GameEngine* game, sf::Event event);
	virtual void update(GameEngine* game);
	virtual void draw(GameEngine* game);

 	virtual void pause();
 	virtual void resume();
};

#endif // INTROSTATE_H
