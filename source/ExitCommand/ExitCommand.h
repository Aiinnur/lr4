#include "../state/ExitState.h"
#include "../state/i_state_manager.h"
#include "../ChangeStateCommand/ChangeStateCommand.h"


struct ExitCommand : public IChangeStateCommand {
    using IChangeStateCommand::IChangeStateCommand;
    void execute() override;
};
