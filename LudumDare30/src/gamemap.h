
#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <string>

class Tile;
class TileType;
class GameMap {
private:
	const int TILE_ROW = 30;
	const int TILE_COL = 40;
	const int TILE_WIDTH = 16;
	const int TILE_HEIGHT = 16;

	std::vector<TileType*> _registered_tile_types;
	Tile** _tiles;

	void set(int x, int y, Tile* tile);
public:
	GameMap();
	virtual ~GameMap();

	void register_type(TileType* type){
		_registered_tile_types.push_back(type);
	}
	void generate_map(const std::string& filename);

	Tile* get(int x, int y);
};


#endif // GAMEMAP_H
