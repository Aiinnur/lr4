#pragma once
#include "../state/i_state_manager.h"
#include "../state/SelectState.h"
class Application : public IStateManager
{
public:
	Application();
	void set_next_state(std::unique_ptr<IState> state) override ;
	int run();
	void apply_deffer_state_change();
private:
	std::unique_ptr<IState> m_ptr_state_current;
	std::unique_ptr<IState> m_ptr_state_next;
};
