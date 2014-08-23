#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "../entities/player.h"
#include "../inputhandler.h"

class GameState : public State{
private:
	InputHandler _input;
	Player _player;

	sf::Font _font;
	sf::Text _msg;
protected:
	static GameState* _instance;
	GameState(){}
public:
	static GameState* instance();
    ~GameState(){}

	virtual void init();
	virtual void cleanup();

	virtual void handle_events(GameEngine* game, sf::Event event);
	virtual void update(GameEngine* game, sf::Time delta);
	virtual void draw(GameEngine* game);

 	virtual void pause();
 	virtual void resume();
};

#endif // GAMESTATE_H
