#pragma once

#include "i_state.h"
#include "i_state_manager.h"


class ExitState : public IState {
public:
	ExitState(IStateManager& state_manager) : IState(state_manager) {}
	bool do_step() override { return false; }; //   false
};

