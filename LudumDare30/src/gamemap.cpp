#include <fstream>
#include <iostream>
#include <SFML/Graphics/Image.hpp>

#include "tiles/tile.h"
#include "gamemap.h"
#include "resourcemanager.h"
using namespace std;

const int GameMap::TILE_ROW = 15;
const int GameMap::TILE_COL = 20;
const int GameMap::TILE_WIDTH = 32;
const int GameMap::TILE_HEIGHT = 32;

GameMap::GameMap(){
 	_tiles = new Tile*[TILE_COL*TILE_ROW];
	for (int i = 0; i < TILE_COL*TILE_ROW; ++i)
	{
		_tiles[i] = nullptr;
	}
}
GameMap::~GameMap(){
	if(_tiles != nullptr){
		for (int i = 0; i < TILE_COL*TILE_ROW; ++i)
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
	for (int i = 0; i < TILE_COL*TILE_ROW; ++i)
	{
		int x = (i%TILE_COL)*TILE_WIDTH;
		int y = (i/TILE_ROW)*TILE_HEIGHT;

	    if(_tiles[i] != nullptr){
            _tiles[i]->draw(window, x, y);
	    }
	}
}
void GameMap::update(sf::Time deltaTime){
	for (int i = 0; i < TILE_COL*TILE_ROW; ++i)
	{
		if(_tiles[i] != nullptr){
            _tiles[i]->update(deltaTime);
		}
	}
}
void GameMap::handle_event(sf::Event event){
	for (int i = 0; i < TILE_COL*TILE_ROW; ++i)
	{
		if(_tiles[i] != nullptr){
            _tiles[i]->handle_event(event);
        }
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
			if(color.a == 0) {
				//- Air tiles, ignoring
				continue;
			}
			for (size_t i = 0; i < _registered_tile_types.size(); ++i)
			{
				if(_registered_tile_types[i]->has_color(color)){
					set(x, y, _registered_tile_types[i]->make_tile());
					found = true;
					break;
				}
			}
			if(!found) cout << "Couldn't find a corresponding tile for Color(" << (int)color.r << "," << (int)color.g << "," << (int)color.b << "," << (int)color.a << ")" << endl;

		}
	}
}
