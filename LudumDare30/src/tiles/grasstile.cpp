#include <iostream>

#include "../animatedsprite.h"
#include "../animation.h"
#include "grasstile.h"

using namespace std;

//- Tile definition
GrassTile::GrassTile() : Tile(32, 32){
	init(32, 32, 0);
}
GrassTile::GrassTile(int w, int h, int type) : Tile(w, h){
	init(w, h, type);
}

void GrassTile::init(int w, int h, int type){
	ResourceManager* res = ResourceManager::instance();
	Animation* anim = res->get_animation("tile", "ground", w, h);
	_sprite = new AnimatedSprite();

	_sprite->set_animation(anim);
	_sprite->set_frame(type);
}

GrassTile::~GrassTile(){

}

void GrassTile::draw(sf::RenderWindow* window){
    window->draw(*_sprite);
}
void GrassTile::update(sf::Time deltaTime){
	_sprite->setPosition(get_rect().left, get_rect().top);
}
void GrassTile::handle_event(InputHandler &){

}


//- Type definition
GrassTileType::GrassTileType(){

}

GrassTileType::~GrassTileType(){

}

bool GrassTileType::has_color(sf::Color color){
	if(color == sf::Color(0, 255, 0, 255)){
		//- Normal grass tile
		_type = 1;
		return true;
	}
	else if(color == sf::Color(0, 210, 0, 255)){
		//- Corner top left grass tile
		_type = 0;
		return true;
	}
	else if(color == sf::Color(0, 230, 0, 255)){
		//- Corner top right grass tile
		_type = 2;
		return true;
	}
	else if(color == sf::Color(0, 180, 0, 255)){
		//- Normal ground beneath grass tile
		_type = 4;
		return true;
	}
	else if(color == sf::Color(0, 140, 0, 255)){
		//- Corner left ground beneath grass tile
		_type = 3;
		return true;
	}
	else if(color == sf::Color(0, 160, 0, 255)){
		//- Corner right ground beneath grass tile
		_type = 5;
		return true;
	}
	else if(color == sf::Color(0, 60, 0, 255)){
		//- Bottom ground
		_type = 6;
		return true;
	}
	_type = 0;
	return false;
}
Tile* GrassTileType::make_tile(int x, int y, int w, int h){
	GrassTile* tile = new GrassTile(w, h, _type);
	tile->set_position(sf::Vector2u(x, y));
	_type = 0;
	return tile;
}
