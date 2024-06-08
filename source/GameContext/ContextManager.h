#pragma once

#include "../Entity/Entity.h"
#include "GameContext.h"
#include <memory>
#include <vector>
#include <stack>

class ContextManager {
public:
    void save_current_context();//сохранение состояния в историю
    void restore_previous_context();//для восстановления раннее сохранённого состояния
    void set_context(GameContext&& context) { m_initial_context = std::move(context); };// устанавливает контекст
    GameContext& get_current_context() { return m_initial_context; };//получить текущее состояние
private:
    GameContext m_initial_context;
    std::stack<GameContext> m_history;
};
