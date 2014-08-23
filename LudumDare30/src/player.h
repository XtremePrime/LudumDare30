#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "animatedSprite.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player : public Entity
{
    public:
        Player();
        virtual ~Player();

        void draw(sf::RenderWindow &window);
        void update(sf::Time deltaTime);

        bool move();
    protected:
    private:
        AnimatedSprite _sprite;
		//sf::Texture _texture;
        //sf::Sprite _sprite;
};

#endif // PLAYER_H
