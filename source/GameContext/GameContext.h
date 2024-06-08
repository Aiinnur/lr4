#pragma once

#include "../Entity/Entity.h"
#include <memory>
#include <vector>


struct GameContext {//это всё что происходит в лабиринте
    GameContext clone() const;
    enum State {
        INGAME, WIN, LOST
    };
    PacMan pacman;
    State state = INGAME;
    std::vector<std::unique_ptr<IDynamicEntity>> dynamic_objects;
    std::vector<std::unique_ptr<IStaticEntity>> static_objects;
};

