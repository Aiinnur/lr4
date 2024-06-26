#pragma once

#include "../Entity/Entity.h"
#include "../GameContext/GameContext.h"
#include <memory>

class GameContext;

struct IGameEvent {
    virtual void handle(GameContext& context) = 0;
    virtual ~IGameEvent() = default;
};

struct WinGame : public IGameEvent {
    void handle(GameContext& context) override { context.state = GameContext::WIN; }
};

struct LostGame : public IGameEvent {
    void handle(GameContext& context) override { context.state = GameContext::LOST; }
};

struct DeleteStaticEntity : public IGameEvent {
    explicit DeleteStaticEntity(IStaticEntity& ptr_entity) : m_ptr_entity(ptr_entity) {}
    void handle(GameContext& context) override;

private:
    IStaticEntity& m_ptr_entity;
};
