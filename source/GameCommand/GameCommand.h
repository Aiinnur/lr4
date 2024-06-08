#pragma once

#include "../ChangeStateCommand/ChangeStateCommand.h"
#include "../GameBuilderDirector/GameBuilderDirector.h"

struct GameCommand : public IChangeStateCommand {
    GameCommand(IStateManager& state_manager, std::unique_ptr<GameBuilderDirector>&& ptr_director)
        : IChangeStateCommand(state_manager), m_ptr_director(std::move(ptr_director)) {};
    void execute() override;
    std::unique_ptr<GameBuilderDirector> m_ptr_director;
};
