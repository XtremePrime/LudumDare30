#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "gamemap.h"
//#include "resourcemanager.h"

class State;
class GameEngine {
private:
    sf::RenderWindow _window;
    GameMap _map;
//    ResourceManager _resource;
	bool _running;
	std::vector<State*> _state_stack;

	int _WIDTH = 640, _HEIGHT = 480;
public:
	sf::RenderWindow* get_window(){ return &_window; }
	void init();
	void cleanup();

	void handle_events();
	void update();
	void draw();

	void change_state(State* state);
	void push_state(State* state);
	void pop_state();

	bool is_running() { return _running; }
	void quit() {
		_running = false;
		_window.close();
	}
};

#endif // GAMEENGINE_H
