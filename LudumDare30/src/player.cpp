#include "player.h"
#include "entity.h"
#include "resourcemanager.h"
#include <iostream>

using namespace std;

Player::Player()
{
    // if(!_texture.loadFromFile("res/player.png"))
    // 	std::cout << "Player loading failed." << std::endl;

    // _sprite.setTexture(_texture);
    // _sprite.setScale(width/_sprite.getLocalBounds().width, height/_sprite.getLocalBounds().height);
    _sprite = *ResourceManager::instance()->get_sprite("player", "walk");
    _sprite.setPosition(sf::Vector2f(100, 100));
    _sprite.play();
}

Player::~Player()
{
    //dtor
}

void Player::update(sf::Time deltaTime)
{
	Entity::update(deltaTime);
    _sprite.update(deltaTime);
}

void Player::draw(sf::RenderWindow* window)
{
    cout << "d ";
	window->draw(_sprite);
}

