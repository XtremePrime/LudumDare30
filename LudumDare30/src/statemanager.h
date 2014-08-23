#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager {
private:
	bool _running;
	std::vector<State*> state_stack;
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

#endif // STATEMANAGER_H
