#include "animation.h"

Animation::Animation() : _texture(NULL){}

void Animation::add_frame(sf::IntRect rect){
	_frames.push_back(rect);
}
void Animation::set_sprite_sheet(const sf::Texture& texture){
	_texture = &texture;
}

const sf::Texture* Animation::get_sprite_sheet() const{
	return _texture;
}
std::size_t Animation::get_size() const{
	return _frames.size();
}
const sf::IntRect& Animation::getFrame(std::size_t id) const{
	return _frames[id];
}
