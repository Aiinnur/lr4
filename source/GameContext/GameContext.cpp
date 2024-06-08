#include "GameContext.h"


GameContext GameContext::clone() const {
    GameContext new_context;
    new_context.pacman = pacman;
    new_context.state = state;
    for (const auto& dynamic_object : dynamic_objects)
        new_context.dynamic_objects.push_back(dynamic_object->clone());
    for (const auto& static_object : static_objects)
        new_context.static_objects.push_back(static_object->clone());
    return new_context;
}
