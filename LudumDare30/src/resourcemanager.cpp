#include <SFML/Graphics/Image.hpp>
#include <sstream>

#include "resourcemanager.h"
#include "animatedsprite.h"

using namespace std;

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}

void ResourceManager::set_dir(string base_dir){
    _base_dir = base_dir;
}

sf::Image* ResourceManager::get_image(string request){
	sf::Image* image = new sf::Image();
	//TODO: actually make the image
	return image;
}
string ResourceManager::get_image_filename(string request){
	stringstream ss;
	ss << _base_dir << "/img/" << request << ".png";

	string filename = ss.str();
	return ss.str();
}

AnimatedSprite* ResourceManager::get_sprite(string request, string animation, int sprite_width, int sprite_height){
	return new AnimatedSprite();
}
string ResourceManager::get_sprite_filename(string request, string animation){
	stringstream ss;
	ss << _base_dir << "/spr/" << request << "/" << animation << ".png";
	string filename = ss.str();
	return filename;
}
