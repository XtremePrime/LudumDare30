#include "inputhandler.h"

void InputHandler::update(sf::Event event)
{
	this->event = event;
}

bool InputHandler::key_pressed(sf::Keyboard::Key key)
{
	return ((event.key.code == key) && ((event.type == sf::Event::KeyPressed)));
}

bool InputHandler::key_pressed(std::vector<sf::Keyboard::Key> keys)
{
	for(int i = 0; i < keys.size(); ++i)
	{
		if(key_pressed(keys[i]))
			return true;
	}
	return false;
}

bool InputHandler::key_released(sf::Keyboard::Key key)
{
	return ((event.key.code == key) && (event.type == sf::Event::KeyReleased));
}

bool InputHandler::key_released(std::vector<sf::Keyboard::Key> keys)
{
	for(int i = 0; i < keys.size(); ++i)
	{
		if(key_released(keys[i]))
			return true;
	}
	return false;
}

bool InputHandler::key_down(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool InputHandler::key_down(std::vector<sf::Keyboard::Key> keys)
{
	for(int i = 0; i < keys.size(); ++i)
	{
		if(key_down(keys[i]))
			return true;
	}
	return false;
}
