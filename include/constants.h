/*
 * Copyright (c) 2020-2023 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "bn_display.h"

namespace constants
{
    const auto screen_half_width = bn::display::width() / 2;
    const auto screen_half_height = bn::display::height() / 2;
}

#endif
