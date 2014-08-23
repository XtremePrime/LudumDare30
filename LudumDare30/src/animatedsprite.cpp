#include "animatedsprite.h"
#include <iostream>

using namespace std;

AnimatedSprite::AnimatedSprite(sf::Time frameTime, bool paused, bool looped) :
    _animation(NULL), _frame_time(frameTime), _current_frame(0), _is_paused(paused), _is_looped(looped), _texture(NULL), _is_flipped(false)
{

}

AnimatedSprite::~AnimatedSprite(){
    //- _texture is deleted by _animation
    if(_animation != NULL){
        delete _animation;
        _animation = NULL;
    }
}

void AnimatedSprite::set_animation(const Animation* animation)
{
    _animation = animation;
    _texture = _animation->get_sprite_sheet();
    _current_frame = 0;
    set_frame(_current_frame);
}

void AnimatedSprite::set_frame_time(sf::Time time)
{
    _frame_time = time;
}

void AnimatedSprite::play()
{
    _is_paused = false;
}

void AnimatedSprite::play(const Animation* animation)
{
    if (get_animation() != animation)
        set_animation(animation);
    play();
}

void AnimatedSprite::pause()
{
    _is_paused = true;
}

void AnimatedSprite::stop()
{
    _is_paused = true;
    _current_frame = 0;
    set_frame(_current_frame);
}

void AnimatedSprite::set_looped(bool looped)
{
    _is_looped = looped;
}

void AnimatedSprite::set_flipped(bool flipped)
{
    _is_flipped = flipped;
}

void AnimatedSprite::set_color(const sf::Color& color)
{
    // Update the vertices' color
    _vertices[0].color = color;
    _vertices[1].color = color;
    _vertices[2].color = color;
    _vertices[3].color = color;
}

const Animation* AnimatedSprite::get_animation() const
{
    return _animation;
}

sf::FloatRect AnimatedSprite::get_local_bounds() const
{
    sf::IntRect rect = _animation->getFrame(_current_frame);

    float width = static_cast<float>(std::abs(rect.width));
    float height = static_cast<float>(std::abs(rect.height));

    return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::get_global_bounds() const
{
    return getTransform().transformRect(get_local_bounds());
}

bool AnimatedSprite::is_looped() const
{
    return _is_looped;
}

bool AnimatedSprite::is_playing() const
{
    return !_is_paused;
}

bool AnimatedSprite::is_flipped() const
{
    return !_is_flipped;
}

sf::Time AnimatedSprite::get_frame_time() const
{
    return _frame_time;
}

void AnimatedSprite::set_frame(std::size_t new_frame, bool reset_time)
{
    if (_animation)
    {
        //calculate new vertex positions and texture coordiantes
        sf::IntRect rect = _animation->getFrame(new_frame);

        _vertices[0].position = sf::Vector2f(0.f, 0.f);
        _vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
        _vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
        _vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

        float left = static_cast<float>(rect.left) + 0.0001f;
        float right = left + static_cast<float>(rect.width);
        float top = static_cast<float>(rect.top);
        float bottom = top + static_cast<float>(rect.height);

        _vertices[0].texCoords = sf::Vector2f(left, top);
        _vertices[1].texCoords = sf::Vector2f(left, bottom);
        _vertices[2].texCoords = sf::Vector2f(right, bottom);
        _vertices[3].texCoords = sf::Vector2f(right, top);
    }

    if (reset_time)
        _current_time = sf::Time::Zero;
}

void AnimatedSprite::update(sf::Time delta_time)
{
    // if not paused and we have a valid animation
    if (!_is_paused && _animation)
    {
        // add delta time
        _current_time += delta_time;

        // if current time is bigger then the frame time advance one frame
        if (_current_time >= _frame_time)
        {
            // reset time, but keep the remainder
            _current_time = sf::microseconds(_current_time.asMicroseconds() % _frame_time.asMicroseconds());

            // get next Frame index
            if (_current_frame + 1 < _animation->get_size())
                _current_frame++;
            else
            {
                // animation has ended
                _current_frame = 0; // reset to start

                if (!_is_looped)
                {
                    _is_paused = true;
                }

            }

            // set the current frame, not reseting the time
            set_frame(_current_frame, false);
        }
    }
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (_animation && _texture)
    {
        states.transform *= getTransform();
        if(_is_flipped) {
            states.transform.scale(-1.0, 1.0);
            states.transform.translate(get_local_bounds().width*-1, 0);
        }
        states.texture = _texture;
        target.draw(_vertices, 4, sf::Quads, states);
    }
}
