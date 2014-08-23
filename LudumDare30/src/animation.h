////////////////////////////////////////////////////////////
//
// Copyright (C) 2014 Maximilian Wagenbach (aka. Foaly) (foaly.f@web.de)
// Modified by Andreas Johansson (aka Aramande) (aramande@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
// Source: https://github.com/LaurentGomila/SFML/wiki/Source%3A-AnimatedSprite
//
////////////////////////////////////////////////////////////

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation {
private:
	std::vector<sf::IntRect> _frames;
	const sf::Texture* _texture;
public:
	Animation();

	void add_frame(sf::IntRect rect);
	void set_sprite_sheet(const sf::Texture& texture);
	const sf::Texture* get_sprite_sheet() const;
	std::size_t get_size() const;
	const sf::IntRect& getFrame(std::size_t id) const;
};

#endif // ANIMATION_H
