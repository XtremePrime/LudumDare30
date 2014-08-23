#include <SFML/Graphics/Image.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include <sstream>

#include "resourcemanager.h"
#include "animatedsprite.h"

using namespace std;
ResourceManager* ResourceManager::_instance;

ResourceManager* ResourceManager::instance(){
	if(_instance == NULL) _instance = new ResourceManager();
	return _instance;
}

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}

void ResourceManager::set_dir(string base_dir){
    _base_dir = base_dir;
}

sf::Image* ResourceManager::get_image(string request){
	sf::Image* image = new sf::Image();
	string filename = get_image_filename(request);
	if(!image->loadFromFile(filename)){
		cout << "Couldn't load image '" << filename << "'" << endl;
		return NULL;
	}

	return image;
}
AnimatedSprite* ResourceManager::get_sprite(string request, string animation, int sprite_width, int sprite_height){
	AnimatedSprite* sprite = new AnimatedSprite();
	string filename = get_sprite_filename(request, animation);
	sf::Texture texture;
	if(!texture.loadFromFile(filename)){
		cout << "Couldn't load sprite '" << filename << "'" << endl;
		return NULL;
	}

	Animation sprite_animation;
	sprite_animation.set_sprite_sheet(texture);
	sf::Vector2u size = texture.getSize();
	if(size.y == 0 || size.y % sprite_width != 0
		|| size.x == 0 || size.x % sprite_height != 0){
		cout << "Mismatched sprite sizes for '" << filename << "'" << endl;
	}

	int width_count = size.x / sprite_width;
	int height_count = size.y / sprite_height;

	//- Assuming that all animations will only have a single row of images
	if(height_count != 1) {
		cout << "This spritesheet is heigher than one sprite, only supporting one line per spritesheet" << endl;
		cout << "Got " << height_count << " line from " << size.y << "/" << sprite_height << endl;
		return NULL;
	}

	for (int count = 0; count < width_count; ++count)
	{
		sprite_animation.add_frame(sf::IntRect(sprite_width * count, 0, sprite_width, sprite_height));
	}
	
	return sprite;
}
sf::Sound* ResourceManager::get_sound(string request){
	sf::Sound* sound = new sf::Sound();
	string filename = get_sound_filename(request);
	sf::SoundBuffer buffer;

	if(!buffer.loadFromFile(filename)){
		cout << "Couldn't load sound '" << filename << "'" << endl;
		return NULL;
	}
	sound->setBuffer(buffer);

	return sound;
}

sf::Music* ResourceManager::get_music(string request){
	sf::Music* music = new sf::Music();
	string filename = get_music_filename(request);
	if(!music->openFromFile(filename)){
		cout << "Couldn't load music '" << filename << "'" << endl;
		return NULL;
	}

	return music;
}

sf::Font* ResourceManager::get_font(string request){
	sf::Font* font = new sf::Font();
	string filename = get_font_filename(request);
	if(!font->loadFromFile(filename)){
		cout << "Couldn't load font '" << filename << "'" << endl;
		return NULL;
	}

	return font;
}

string ResourceManager::get_sound_filename(string request){
	stringstream ss;
	ss << _base_dir << "/sfx/" << request << ".wav";

	string filename = ss.str();
	return ss.str();
}
string ResourceManager::get_music_filename(string request){
	stringstream ss;
	ss << _base_dir << "/music/" << request << ".ogg";

	string filename = ss.str();
	return ss.str();
}
string ResourceManager::get_font_filename(string request){
	stringstream ss;
	ss << _base_dir << "/font/" << request << ".ttf";

	string filename = ss.str();
	return ss.str();
}
string ResourceManager::get_image_filename(string request){
	stringstream ss;
	ss << _base_dir << "/img/" << request << ".png";

	string filename = ss.str();
	return ss.str();
}
string ResourceManager::get_sprite_filename(string request, string animation){
	stringstream ss;
	ss << _base_dir << "/sprite/" << request << "/" << animation << ".png";
	string filename = ss.str();
	return filename;
}
