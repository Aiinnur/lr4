#pragma once

#include "../IDrawable/IDrawable.h"
#include "../IPreparable/IPreparable.h"

class Room;
class IEntity;

struct IRoomSide : public IPreparable {
    virtual bool enter(IEntity& entity) = 0;
    void prepare_for_drawing() override {};

};

class Pass : public IRoomSide {
public:
    Pass(Room& room1, Room& room2) : m_room1(room1), m_room2(room2) {}
    void draw_into(sf::RenderWindow& window) override { /*  */ }
    bool enter(IEntity& entity) override;
    void prepare_for_drawing() override {};
private:
    Room& m_room1;
    Room& m_room2;
};

class Wall : public IRoomSide {
public:
    explicit Wall(Room& room) : m_room(room) {};
    void draw_into(sf::RenderWindow& window) override;
    bool enter(IEntity& entity) override;
    void prepare_for_drawing () override;
private:
    Room& m_room;
    sf::Vertex m_line[2];
};
