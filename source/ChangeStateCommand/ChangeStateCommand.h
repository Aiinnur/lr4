#pragma once
#include <memory>
#include "../ISelectCommand/ISelectCommand.h"
#include "../state/i_state_manager.h"

class IStateManager;

struct IChangeStateCommand : public ISelectCommand
{
public:
	IChangeStateCommand(IStateManager& state_manager) : m_state_manager(state_manager) { }
protected:
	IStateManager& m_state_manager;
};
