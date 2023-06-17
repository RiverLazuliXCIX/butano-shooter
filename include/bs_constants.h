#ifndef BS_CONSTANTS_H
#define BS_CONSTANTS_H

#include "bn_display.h"

namespace bs::constants
{
    const auto screen_half_width = bn::display::width() / 2;
    const auto screen_half_height = bn::display::height() / 2;
}

#endif
