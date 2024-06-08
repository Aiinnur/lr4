#pragma once

#include "../Entity/Entity.h"
#include "GameContext.h"
#include <memory>
#include <vector>
#include <stack>

class ContextManager {
public:
    void save_current_context();//���������� ��������� � �������
    void restore_previous_context();//��� �������������� ������ ����������� ���������
    void set_context(GameContext&& context) { m_initial_context = std::move(context); };// ������������� ��������
    GameContext& get_current_context() { return m_initial_context; };//�������� ������� ���������
private:
    GameContext m_initial_context;
    std::stack<GameContext> m_history;
};
