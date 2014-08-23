#include <SFML/Graphics.hpp>
#include <vector>

class InputHandler
{
private:
	void update();

	void key_pressed(int key);
	void key_pressed(std::vector<int> keys);

	void key_released(int key);
	void key_released(std::vector<int> keys);
public:
	sf::Event event;
};