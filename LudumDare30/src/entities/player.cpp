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
    ResourceManager* res = ResourceManager::instance();
    _animations[AnimationState::IDLE] = res->get_animation("player", "idle", 32, 32);
    _animations[AnimationState::WALK] = res->get_animation("player", "walk", 32, 32);

    //AnimatedSprite* sprite = new AnimatedSprite();

    _sprite.set_animation(_animations[AnimationState::IDLE]);
    //_sprite = *ResourceManager::instance()->get_sprite("player", "idle");
    _sprite.setPosition(sf::Vector2f(100, 100));
    _sprite.play();
    _sprite.set_looped(true);
    _speed = 50;
}

Player::~Player()
{
    //dtor
}
void Player::handle_events(InputHandler& handler){
    //- Cancel out the movement
    _movement = sf::Vector2f(0.f, 0.f);

    if(handler.key_pressed(sf::Keyboard::Left) || handler.key_pressed(sf::Keyboard::A)){
        //- Move player left
        _sprite.play(_animations[AnimationState::WALK]);
        _movement.x -= _speed;
        _sprite.set_flipped(true);
        _sprite.set_looped(true);
        std::cout << "Reached 1" << std::endl; 
    }
    else if(handler.key_pressed(vector<sf::Keyboard::Key>({ sf::Keyboard::D, sf::Keyboard::Right }))){
        //- Move player right
        _sprite.play(_animations[AnimationState::WALK]);
        _movement.x += _speed;
        _sprite.set_flipped(false);
        _sprite.set_looped(true);
        std::cout << "Reached 2" << std::endl;
    }
    else{
        _sprite.play(_animations[AnimationState::IDLE]);
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

