#ifndef GRASSTILE_H
#define GRASSTILE_H
#include "tile.h"

class AnimatedSprite;
class GrassTile : public Tile{
private:
	AnimatedSprite* _sprite;
	void init(int w, int h, int type);
public:
	GrassTile();
	GrassTile(int w, int h, int type);
	~GrassTile();
	virtual void draw(sf::RenderWindow* window);
    virtual void update(sf::Time deltaTime);
	virtual void handle_event(InputHandler &event);
};

class GrassTileType : public TileType {
private:
	int _type;
public:
	GrassTileType();
	~GrassTileType();
	virtual bool has_color(sf::Color color);
	virtual Tile* make_tile(int x, int y, int w, int h);
};

#endif // GRASSTILE_H
