
#include "grasstile.h"

//- Tile definition
GrassTile::GrassTile(){

}

GrassTile::~GrassTile(){

}

void GrassTile::handle_event(GameEngine* game){

}
void GrassTile::update(GameEngine* game){

}
void GrassTile::draw(GameEngine* game){

}

//- Type definition
GrassTileType::GrassTileType(){

}

GrassTileType::~GrassTileType(){

}

bool GrassTileType::has_color(sf::Color color){
	return false;
}
Tile* GrassTileType::make_tile(){
	return new GrassTile();
}
