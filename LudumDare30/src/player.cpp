#include "player.h"
#include "entity.h"
#include <iostream>

Player::Player()
{
    if(!_texture.loadFromFile("res/player.png"))
    	std::cout << "Player loading failed." << std::endl;

    _sprite.setTexture(_texture);
    _sprite.setScale(width/_sprite.getLocalBounds().width, height/_sprite.getLocalBounds().height);
}

Player::~Player()
{
    //dtor
}

void Player::update(sf::Time deltaTime)
{
	Entity::update(deltaTime);

}

void Player::draw(sf::RenderWindow &window)
{

}

