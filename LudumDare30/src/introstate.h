#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "state.h"
#include "inputhandler.h"

class IntroState : public State{
private:
	InputHandler _input;

	short int _menu_item = 0; // 0 = top option
	const short int _TOTAL_MENU_ITEMS = 1;

	// Drawing variables
	sf::Font _font;
	sf::Text _title;
	sf::Text _start;
	sf::Text _quit;
	sf::CircleShape _selector;

	//Audio variables
	sf::Sound _btn_up;
	sf::Sound _btn_down;

	void move_selector(int idx);
	sf::Text _msg;
protected:
	static IntroState* _instance;
	IntroState(){}
public:
	static IntroState* instance();
    ~IntroState(){

    }

	virtual void init();
	virtual void cleanup();

	virtual void handle_events(GameEngine* game, sf::Event event);
	virtual void update(GameEngine* game, sf::Time deltaTime);
	virtual void draw(GameEngine* game);

 	virtual void pause();
 	virtual void resume();
};

#endif // INTROSTATE_H
