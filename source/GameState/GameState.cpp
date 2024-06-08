#pragma once
#include "GameState.h"
#include "../Entity/Entity.h"
#include "../state/i_state_manager.h"
#include "../GameContext/GameContext.h"
#include "../GameContext/ContextManager.h"
#include "../config/config.h"
#include <memory>
#include <iostream>

GameState::GameState(IStateManager& state_manager, const std::string& window_title, const sf::VideoMode& mode) :
    IWindowKeeper(mode, window_title),
    IState(state_manager) {
}

void GameState::set_context(GameContext&& context) {
    m_context_manager.set_context(std::move(context));//устанавливаем новый контекст
    m_context_manager.save_current_context();// сохраняет в историю
}
