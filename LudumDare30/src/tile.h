#ifndef TILE_H
#define TILE_H
#include "gameengine.h"

class Tile {
private:

protected:
	Tile(){}
public:
	virtual void handle_event(GameEngine* game) = 0;
	virtual void update(GameEngine* game) = 0;
	virtual void draw(GameEngine* game) = 0;
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
