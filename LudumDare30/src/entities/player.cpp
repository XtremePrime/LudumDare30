#include "player.h"
#include "entity.h"
#include "../resourcemanager.h"
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
    _sprite.set_looped(true);
    _speed = 40;
}

Player::~Player()
{
    //dtor
}
void Player::handle_events(InputHandler& handler){
    //- Cancel out the movement
    _movement = sf::Vector2f(0.f, 0.f);

    if(handler.key_pressed(vector<sf::Keyboard::Key>({ sf::Keyboard::Left, sf::Keyboard::D }))){
        //- Move player left
        _movement.x -= _speed;
        _sprite.set_flipped(true);
    }

    if(handler.key_pressed(vector<sf::Keyboard::Key>({ sf::Keyboard::Right, sf::Keyboard::A }))){
        //- Move player right
        _movement.x += _speed;
        _sprite.set_flipped(false);
    }
}

void Player::update(sf::Time deltaTime)
{
    //cout << _movement.x << "; ";
	Entity::update(deltaTime);
    _sprite.move(_movement * deltaTime.asSeconds());
    _sprite.update(deltaTime);


}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(_sprite);
}

