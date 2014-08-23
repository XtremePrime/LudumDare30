#ifndef GRASSTILE_H
#define GRASSTILE_H
#include "tile.h"

class GrassTile : public Tile{
private:
public:
	GrassTile();
	~GrassTile();
	virtual void handle_event(GameEngine* game);
	virtual void update(GameEngine* game);
	virtual void draw(GameEngine* game);
};

class GrassTileType : public TileType {
private:
public:
	GrassTileType();
	~GrassTileType();
	virtual bool has_color(sf::Color color);
	virtual Tile* make_tile();
};

#endif // GRASSTILE_H
