#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprites.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_shape_size.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_display.h"
#include "bn_math.h"

#include "reticle.h"

#include "bn_regular_bg_items_background.h"
#include "bn_sprite_items_reticle_sprite.h"

int main()
{
    bn::core::init();

    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);
    bn::sprite_ptr reticle_sprite = bn::sprite_items::reticle_sprite.create_sprite(0, 0);

    while (true)
    {
        reticle_movement(reticle_sprite);

        bn::core::update();
    }
}