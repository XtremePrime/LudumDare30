#ifndef TILE_H
#define TILE_H
#include "../gameengine.h"

class Tile {
private:

protected:
	Tile(){}
public:
	virtual ~Tile(){}
	virtual void draw(sf::RenderWindow* window, int x, int y) = 0;
    virtual void update(sf::Time deltaTime) = 0;
	virtual void handle_event(sf::Event event) = 0;
};

class TileType {
private:
protected:
	TileType(){}
public:
	virtual ~TileType(){}

	virtual bool has_color(sf::Color color) = 0;
	virtual Tile* make_tile() = 0;
};

#endif // TILE_H
