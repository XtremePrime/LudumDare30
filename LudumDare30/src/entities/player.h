#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "../inputhandler.h"
#include "../animatedSprite.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player : public Entity
{
    public:
        Player();
        virtual ~Player();

        void draw(sf::RenderWindow* window);
        void update(sf::Time deltaTime);
        void handle_events(InputHandler& handler);

        bool move();
    protected:
    private:
        sf::Vector2f _movement;
        double _speed;
        Animation* _animations[10];
        AnimatedSprite _sprite;
		//sf::Texture _texture;
        //sf::Sprite _sprite;
};

enum AnimationState{
    IDLE, WALK
};

#endif // PLAYER_H
