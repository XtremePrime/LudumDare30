#ifndef TILE_H
#define TILE_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "../gameengine.h"

class Tile {
private:
	sf::IntRect _rect;
protected:
	Tile(int w, int h) : _rect(sf::IntRect(0, 0, w, h)){}
public:
	virtual ~Tile(){}
	virtual void draw(sf::RenderWindow* window) = 0;
    virtual void update(sf::Time deltaTime) = 0;
	virtual void handle_event(InputHandler &event) = 0;

	virtual void set_position(sf::Vector2u pos) { _rect.left = pos.x; _rect.top = pos.y; }
	virtual const sf::IntRect& get_rect() const { return _rect; }
};

class TileType {
private:
protected:
	TileType(){}
public:
	virtual ~TileType(){}

	virtual bool has_color(sf::Color color) = 0;
	virtual Tile* make_tile(int x, int y, int w, int h) = 0;
};

#endif // TILE_H
