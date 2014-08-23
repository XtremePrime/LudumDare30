#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include <SFML/Graphics.hpp>

class State;
class GameEngine {
private:
    sf::RenderWindow _window;
	bool _running;
	std::vector<State*> _state_stack;
public:
	void init();
	void cleanup();

	void handle_events();
	void update();
	void draw();

	void change_state(State* state);
	void push_state(State* state);
	void pop_state();

	bool running() { return _running; }
	void quit() { _running = false; }
};

#endif // GAMEENGINE_H
