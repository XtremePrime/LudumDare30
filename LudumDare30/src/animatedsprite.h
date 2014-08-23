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

#ifndef ANIMATEDSPRITE_INCLUDE
#define ANIMATEDSPRITE_INCLUDE

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>

#include "Animation.h"

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
private:
    const Animation* _animation;
    sf::Time _frame_time;
    sf::Time _current_time;
    std::size_t _current_frame;
    bool _is_paused;
    bool _is_looped;
    const sf::Texture* _texture;
    sf::Vertex _vertices[4];

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    explicit AnimatedSprite(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);

    void update(sf::Time deltaTime);
    void set_animation(const Animation& animation);
    void set_frame_time(sf::Time time);
    void play();
    void play(const Animation& animation);
    void pause();
    void stop();
    void set_looped(bool looped);
    void set_color(const sf::Color& color);
    const Animation* get_animation() const;
    sf::FloatRect get_local_bounds() const;
    sf::FloatRect get_global_bounds() const;
    bool is_looped() const;
    bool is_playing() const;
    sf::Time get_frame_time() const;
    void set_frame(std::size_t newFrame, bool resetTime = true);

};

#endif // ANIMATEDSPRITE_INCLUDE
