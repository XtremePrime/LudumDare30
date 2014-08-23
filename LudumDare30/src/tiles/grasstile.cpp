
#include "../animatedsprite.h"
#include "../animation.h"
#include "grasstile.h"

//- Tile definition
GrassTile::GrassTile(){
	ResourceManager* res = ResourceManager::instance();
	Animation* anim = res->get_animation("tile", "ground", 32, 32);
	_sprite = new AnimatedSprite();

	_sprite->set_animation(anim);
	_sprite->set_frame(0);
}

GrassTile::~GrassTile(){

}

void GrassTile::draw(sf::RenderWindow* window, int x, int y){
	_sprite->setPosition(x, y);
    window->draw(*_sprite);
}
void GrassTile::update(sf::Time deltaTime){

}
void GrassTile::handle_event(sf::Event event){

}


//- Type definition
GrassTileType::GrassTileType(){

}

GrassTileType::~GrassTileType(){

}

bool GrassTileType::has_color(sf::Color color){
	if(color == sf::Color(0, 255, 0, 255)){
		//- Normal grass tile
		return true;
	}
	else if(color == sf::Color(0, 210, 0, 255)){
		//- Corner top left grass tile
		return true;
	}
	else if(color == sf::Color(0, 230, 0, 255)){
		//- Corner top left grass tile
		return true;
	}
	else if(color == sf::Color(0, 180, 0, 255)){
		//- Normal ground beneath grass tile
		return true;
	}
	return false;
}
Tile* GrassTileType::make_tile(){
	return new GrassTile();
}
