#include <fstream>
#include <iostream>
#include <SFML/Graphics/Image.hpp>

#include "tile.h"
#include "gamemap.h"
#include "resourcemanager.h"
using namespace std;

const int GameMap::TILE_ROW = 30;
const int GameMap::TILE_COL = 40;
const int GameMap::TILE_WIDTH = 16;
const int GameMap::TILE_HEIGHT = 16;

GameMap::GameMap(){
 	_tiles = new Tile*[TILE_COL*TILE_ROW];
}
GameMap::~GameMap(){
	if(_tiles != NULL){
		for (int i = 0; i < TILE_COL*TILE_ROW; ++i)
		{
			if(_tiles[i] != NULL){
				delete _tiles[i];
				_tiles[i] = NULL;
			}
		}
		delete[] _tiles;
		_tiles = NULL;
	}
}
void GameMap::set(int x, int y, Tile* tile){
    _tiles[y * TILE_ROW + x] = tile;
}
Tile* GameMap::get(int x, int y) const{
    return _tiles[y * TILE_ROW + x];
}
void GameMap::generate_map(const string& map){
	ResourceManager* res = ResourceManager::instance();
	sf::Image img = *res->get_image(map);

	sf::Vector2u size = img.getSize();
	for (size_t y = 0; y < size.y; ++y){
		for (size_t x = 0; x < size.x; ++x)
		{
			bool found = false;
			sf::Color color = img.getPixel(x, y);
			for (size_t i = 0; i < _registered_tile_types.size(); ++i)
			{
				if(_registered_tile_types[i]->has_color(color)){
					set(x, y, _registered_tile_types[i]->make_tile());
					found = true;
					break;
				}
			}
			if(!found) cout << "Couldn't find a corresponding tile for Color(" << color.r << "," << color.g << "," << color.b << "," << color.a << ")" << endl;
		}
	}
}
