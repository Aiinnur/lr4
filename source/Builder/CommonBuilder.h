#pragma once
#include "../GameState/GameState.h"
#include <random>
#include "IGameBuilder.h"


struct CommonBuilder  : public IGameBuilder {
    CommonBuilder(float width, float height, float room_size);
    virtual void create_rooms() = 0;
    void set_rooms_sides() override;
    void create_context(float dynamic_objects_ratio) override;
    void create_state(IStateManager& state_manager, std::string window_title) override;
    void set_all_to_state() override;
    std::unique_ptr<GameState> get_game() override { return std::move(m_game_state); };
protected:
    float m_width;
    float m_height;
    float m_room_size;
    std::vector<std::vector<std::unique_ptr<Room>>> m_rooms;
    GameContext m_context;
    std::unique_ptr<GameState> m_game_state;
protected:
    std::vector<Room*> m_available_rooms;
    void prepare_available_rooms();
};
