#include "ExitCommand.h"
#include "../state/ExitState.h"
#include "../state/i_state_manager.h"
#include "../state/i_state_manager.h"

void ExitCommand::execute() {
    m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
};
