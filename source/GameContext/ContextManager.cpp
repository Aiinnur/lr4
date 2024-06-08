#include "ContextManager.h"

void ContextManager::restore_previous_context() {
    if (m_history.size() > 1)
        m_history.pop();
    else
        m_history.top() = m_initial_context.clone();
}

void ContextManager::save_current_context() {//��������� � ������� ������� ���������
    m_history.push(m_initial_context.clone());
}
