#pragma once
#include "../IWindowKeeper/IWindowKeeper.h"
#include "../Menu/Menu.h"
#include "i_state.h"
#include <string>


class IState;
class IWindowKeeper;

class SelectState : public IState, public IWindowKeeper
{
public:
	SelectState(IStateManager& state_manager, const std::string& window_title);
    bool do_step() override;
protected:
    void event_handling() override ;
    void update() override ;
    void render() override ;
private:
    Menu m_menu;
};
