
#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <string>

class Tile;
class TileType;
class GameMap {
private:
	static const int TILE_ROW;
	static const int TILE_COL;
	static const int TILE_WIDTH;
	static const int TILE_HEIGHT;

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

	Tile* get(int x, int y) const;
};


#endif // GAMEMAP_H
