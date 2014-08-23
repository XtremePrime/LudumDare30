#include "InputHandler.h"

void InputHandler::update(sf::Event event)
{
	this->event = event
}

bool InputHandler::key_pressed(int key)
{
	return ((event.Key.Code == key) && ((event.Type == sf::Event::KeyPressed)));
}

bool InputHandler::key_pressed(std::vector<int> keys)
{
	for(int i = 0; i < keys.size(); ++i)
	{
		// if(event.Key.Code == keys[i] && event.Type == sf::Event::KeyPressed)
		if(key_pressed(keys[i]))
			return true;
	}
	return false;
}

bool InputHandler::key_released(int key)
{
	return ((event.Key.Code == key) && (event.Type == sf::Event::KeyReleased));
}

bool InputHandler::key_released(std::vector<int> keys)
{
	for(int i = 0; i < keys.size(); ++i)
	{
		// if(event.Key.Code == keys[i] && event.Type == sf::Event::KeyReleased)
		if(key_released(keys[i]))
			return true;
	}
	return false;
}

bool InputHandler::key_down(sf::RenderWindow &window, int key)
{
	return window.GetInput().IsKeyDown(key);
}

bool InputHandler::key_down(sf::RenderWindow &window, std::vector<int> keys)
{
	for(int i = 0; i < keys.size(); ++i)
	{
		// if(window.GetInput().IsKeyDown(keys[i]))
		if(key_down(keys[i]))
			return true;
	}
	return false;
}