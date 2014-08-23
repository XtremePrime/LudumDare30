#ifndef GRASSTILE_H
#define GRASSTILE_H
#include "tile.h"

class AnimatedSprite;
class GrassTile : public Tile{
private:
	AnimatedSprite* _sprite;
public:
	GrassTile();
	~GrassTile();
	virtual void draw(sf::RenderWindow* window, int x, int y);
    virtual void update(sf::Time deltaTime);
	virtual void handle_event(sf::Event event);
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
