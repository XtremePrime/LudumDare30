#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>

class AnimatedSprite;
class ResourceManager {
private:
    std::string _base_dir;
protected:
    static ResourceManager* _instance;
	ResourceManager();
public:
	static ResourceManager* instance();
    virtual ~ResourceManager();

    void set_dir(std::string base_dir);

	std::string get_sound_filename(std::string request);
	sf::Sound* get_sound(std::string request);

	std::string get_music_filename(std::string request);
	sf::Music* get_music(std::string request);

	std::string get_font_filename(std::string request);
	sf::Font* get_font(std::string request);

	sf::Image* get_image(std::string request);
	std::string get_image_filename(std::string request);

	AnimatedSprite* get_sprite(std::string request, std::string animation, int sprite_width=32, int sprite_height=32);
	std::string get_sprite_filename(std::string request, std::string animation);
};

#endif // RESOURCEMANAGER_H
