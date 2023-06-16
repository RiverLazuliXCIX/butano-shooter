#include "bn_keypad.h"
#include "bn_sprites.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_shape_size.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_display.h"
#include "bn_math.h"
#include "constants.h"

const bn::fixed kSpeed = 0.5;
const bn::fixed kMaxSpeed = 5;
const bn::fixed kDeceleration = 1.1;

bn::fixed velocity_x = 0;
bn::fixed velocity_y = 0;

void reticle_movement(bn::sprite_ptr &reticle_sprite)
{
    auto reticle_radius = reticle_sprite.shape_size().width() / 2;

    auto direction_x = 0;
    auto direction_y = 0;

    if (bn::keypad::right_held())
    {
        direction_x = 1;
    }
    else if (bn::keypad::left_held())
    {
        direction_x = -1;
    }

    if (bn::keypad::down_held())
    {
        direction_y = 1;
    }
    else if (bn::keypad::up_held())
    {
        direction_y = -1;
    }

    if (direction_x != 0)
    {
        auto max_velocity = kMaxSpeed * direction_x;
        auto higher_velocity = velocity_x + kSpeed * direction_x;
        velocity_x = abs(max_velocity) < abs(higher_velocity) ? max_velocity : higher_velocity;
    }
    else
    {
        auto lower_velocity = velocity_x / kDeceleration;
        velocity_x = abs(lower_velocity) > kSpeed ? lower_velocity : 0;
    }

    if (direction_y != 0)
    {
        auto max_velocity = kMaxSpeed * direction_y;
        auto higher_velocity = velocity_y + kSpeed * direction_y;
        velocity_y = abs(max_velocity) < abs(higher_velocity) ? max_velocity : higher_velocity;
    }
    else
    {
        auto lower_velocity = velocity_y / kDeceleration;
        velocity_y = abs(lower_velocity) > kSpeed ? lower_velocity : 0;
    }

    if (reticle_sprite.x() < -constants::screen_half_width - reticle_radius)
    {
        reticle_sprite.set_x(constants::screen_half_width);
    }
    else if (reticle_sprite.x() > constants::screen_half_width + reticle_radius)
    {
        reticle_sprite.set_x(-constants::screen_half_width);
    }
    else
    {
        reticle_sprite.set_x(reticle_sprite.x() + velocity_x);
    }

    if (reticle_sprite.y() < -constants::screen_half_height - reticle_radius)
    {
        reticle_sprite.set_y(constants::screen_half_height);
    }
    else if (reticle_sprite.y() > constants::screen_half_height + reticle_radius)
    {
        reticle_sprite.set_y(-constants::screen_half_height);
    }
    else
    {
        reticle_sprite.set_y(reticle_sprite.y() + velocity_y);
    }
}