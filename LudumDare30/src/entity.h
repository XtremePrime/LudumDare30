#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        virtual void update(sf::Time deltaTime);
        virtual void draw(sf::RenderWindow &window) = 0;
    protected:
    	int height, width;
    private:
};

#endif // ENTITY_H
