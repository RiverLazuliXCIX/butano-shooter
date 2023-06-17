#include "bs_reticle.h"

#include "bn_regular_bg_items_background.h"

#include "bn_core.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

int main()
{
    bn::core::init();
    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);
    bs::reticle reticle = bs::reticle();

    while (true)
    {
        reticle.update();
        bn::core::update();
    }
}