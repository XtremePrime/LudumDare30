#include <fstream>
#include <iostream>
#include <SFML/Graphics/Image.hpp>

#include "tiles/tile.h"
#include "gamemap.h"
#include "resourcemanager.h"
using namespace std;

const int GameMap::TILE_ROW_COUNT = 15;
const int GameMap::TILE_COL_COUNT = 20;
const int GameMap::TILE_WIDTH = 32;
const int GameMap::TILE_HEIGHT = 32;

GameMap::GameMap(){
 	_tiles = new Tile*[TILE_COL_COUNT*TILE_ROW_COUNT];
	for (int i = 0; i < TILE_COL_COUNT*TILE_ROW_COUNT; ++i)
	{
		_tiles[i] = nullptr;
	}
}
GameMap::~GameMap(){
	if(_tiles != nullptr){
		for (int i = 0; i < TILE_COL_COUNT*TILE_ROW_COUNT; ++i)
		{
			if(_tiles[i] != nullptr){
				delete _tiles[i];
				_tiles[i] = nullptr;
			}
		}
		delete[] _tiles;
		_tiles = nullptr;
	}
}
void GameMap::draw(sf::RenderWindow* window){
	for (int i = 0; i < TILE_COL_COUNT*TILE_ROW_COUNT; ++i)
	{
	    if(_tiles[i] != nullptr){
            _tiles[i]->draw(window);
	    }
	}
}
void GameMap::update(sf::Time deltaTime){
	for (int i = 0; i < TILE_COL_COUNT*TILE_ROW_COUNT; ++i)
	{
		if(_tiles[i] != nullptr){
            _tiles[i]->update(deltaTime);
		}
	}
}
void GameMap::handle_events(InputHandler &event){
	for (int i = 0; i < TILE_COL_COUNT*TILE_ROW_COUNT; ++i)
	{
		if(_tiles[i] != nullptr){
            _tiles[i]->handle_event(event);
        }
	}
}

void GameMap::set(int x, int y, Tile* tile){
    _tiles[y * TILE_COL_COUNT + x] = tile;
}
Tile* GameMap::get(int x, int y) const{
    return _tiles[y * TILE_ROW_COUNT + x];
}
void GameMap::generate_map(const string& map){
	ResourceManager* res = ResourceManager::instance();
	sf::Image* img = res->get_image(map);

	sf::Vector2u size = img->getSize();
	for (size_t y = 0; y < size.y; ++y){
		for (size_t x = 0; x < size.x; ++x)
		{
			bool found = false;
			sf::Color color = img->getPixel(x, y);

			if(color.a == 0) {
				//- Air tiles, ignoring
				continue;
			}

			int pixel_x = x*TILE_WIDTH;
			int pixel_y = y*TILE_HEIGHT;
			for (size_t i = 0; i < _registered_tile_types.size(); ++i)
			{
				if(_registered_tile_types[i]->has_color(color)){
					set(x, y, _registered_tile_types[i]->make_tile(pixel_x, pixel_y, TILE_WIDTH, TILE_HEIGHT));
					found = true;
					break;
				}
			}
			if(!found) cout << "Couldn't find a corresponding tile for Color(" << (int)color.r << "," << (int)color.g << "," << (int)color.b << "," << (int)color.a << ")" << endl;

		}
	}
	delete img;
	img = nullptr;
}
