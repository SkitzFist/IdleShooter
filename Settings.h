#pragma once
#ifndef _Settings
#define _Settings

#include "Vec2.h"

namespace Settings
{
    static constexpr const Vec2<int>  WORLD_SIZE = {800,600};
    static constexpr const int CELL_SIZE = 32;
    static constexpr const Vec2<int> GRID_SIZE = {WORLD_SIZE.x / CELL_SIZE, WORLD_SIZE.y / CELL_SIZE +1};
    
    //DEBUG
    static bool debugMenu = true;    

} // namespace Settings

#endif