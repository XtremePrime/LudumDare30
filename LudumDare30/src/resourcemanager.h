#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics/Image.hpp>
#include <string>

class AnimatedSprite;
class ResourceManager {
private:
    std::string _base_dir;
public:
	ResourceManager();
	~ResourceManager();

    void set_dir(std::string base_dir);

	sf::Image* get_image(std::string request);
	std::string get_image_filename(std::string request);

	AnimatedSprite* get_sprite(std::string request, std::string animation, int sprite_width=32, int sprite_height=32);
	std::string get_sprite_filename(std::string request, std::string animation);
};

#endif // RESOURCEMANAGER_H
