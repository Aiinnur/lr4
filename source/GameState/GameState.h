
/*�������� ���������� EVENT, UPDATE, RENDER*/




#pragma once

#include "../state/i_state.h"
#include "../IWindowKeeper/IWindowKeeper.h"
#include "../RoomAndMaze/RoomAndMaze.h"
#include "../GameContext/GameContext.h"
#include "../GameContext/ContextManager.h"

class GameState : public IState, public IWindowKeeper {//��������� ����: ��, ��� � ���������+��������(�����)
public:
    GameState(IStateManager& state_manager, const std::string& window_title, const sf::VideoMode& mode);
    void set_maze(Maze&& maze) { m_maze = std::move(maze); };//�������� ��������� ���������
    void set_context(GameContext&& context);//�������� ���������� ���� ��� � ���������
    bool do_step() override { return true; };
    void event_handling() override {};
    void update() override {};
    void render() override {};
private:
    ContextManager m_context_manager;
    Maze m_maze;
};
