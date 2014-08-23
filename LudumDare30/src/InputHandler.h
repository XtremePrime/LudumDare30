#include <SFML/Graphics.hpp>
#include <vector>

class InputHandler
{
private:
	void update();

	bool key_pressed(int key);
	bool key_pressed(std::vector<int> keys);

	bool key_released(int key);
	bool key_released(std::vector<int> keys);

	bool key_down(sf::RenderWindow &window, int key);
	bool key_down(sf::RenderWindow &window, std::vector<int> keys);
public:
	sf::Event event;
};