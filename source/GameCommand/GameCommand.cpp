#include "GameCommand.h"
void GameCommand::execute() {
    auto state = m_ptr_director->build(m_state_manager);
    m_state_manager.set_next_state(std::move(state));
}

