#include "GameEvent.h"
#include <algorithm>

void DeleteStaticEntity::handle(GameContext& context) {
    auto& vec = context.static_objects;
    auto it = std::find_if(vec.begin(), vec.end(), [this](const auto& el) { return el.get() == &m_ptr_entity; });
    if (it == vec.end()) {
        throw std::runtime_error{ "No food for delete" };
    }
    vec.erase(it);
}
