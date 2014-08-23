#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class State;
class GameEngine {
private:
    sf::RenderWindow _window;
	bool _running;
	std::vector<State*> _state_stack;
public:
	sf::RenderWindow* window(){ return &_window; }
	void init();
	void cleanup();

	void handle_events();
	void update();
	void draw();

	void change_state(State* state);
	void push_state(State* state);
	void pop_state();

	bool running() { return _running; }
	void quit() {
		_running = false;
		_window.close();
	}
};

#endif // GAMEENGINE_H
