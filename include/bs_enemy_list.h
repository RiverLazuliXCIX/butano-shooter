#ifndef BS_ENEMY_LIST_H
#define BS_ENEMY_LIST_H

#include "bs_enemy.h"
#include "bs_constants.h"

#include "bn_forward_list.h"

namespace bs
{
    class enemy_list
    {
    public:
        enemy_list();
        void update();

    private:
        bn::forward_list<enemy, constants::max_enemies> _enemy_list;
    };
}

#endif