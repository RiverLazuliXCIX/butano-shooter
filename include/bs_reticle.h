#ifndef BS_RETICLE_H
#define BS_RETICLE_H

#include "bn_sprite_ptr.h"

namespace bs
{
    class reticle
    {
    private:
        bn::sprite_ptr _sprite;

        bn::sprite_ptr draw();
        void movement();
        void wrap_around_screen();

    public:
        reticle();
        void update();
    };
}
#endif
