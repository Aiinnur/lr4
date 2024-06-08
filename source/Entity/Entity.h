
//
// 
// 
// Õ≈ «¿ ŒÕ◊≈ÕŒ. ≈Ÿ® œŒ—≈Ÿ≈Õ»≈
// 
// 
// 
#pragma once

#include "../IDrawable/IDrawable.h"
#include "../RoomAndMaze/RoomAndMaze.h"
#include "../IPreparable/IPreparable.h"
#include "../Visitor/IVisitor.h"
#include "../GameEvent/GameEvent.h"


class IEntity : public IPreparable{
public:
    void set_location(Room& ptr_room) {
        m_ptr_room = &ptr_room;
        prepare_for_drawing();
    }

    Room& get_location() { return *m_ptr_room; }

protected:
    Room* m_ptr_room;
};

struct IStaticEntity : public IEntity, public IVisitable {
    virtual std::unique_ptr<IStaticEntity> clone() const = 0;
};

struct IDynamicEntity : public IEntity, public IVisitable {
    virtual std::unique_ptr<IDynamicEntity> clone() const = 0;
    virtual void action() = 0;
};

struct Food : public IStaticEntity {
    void draw_into(sf::RenderWindow& window) override;
    std::unique_ptr<IStaticEntity> clone() const override { return std::make_unique<Food>(*this); }
    void prepare_for_drawing() override;
    std::unique_ptr<IGameEvent> accept(IVisitor* ptr_visitor) override;
private:
    sf::CircleShape m_food_circle;
};

struct Enemy : public IDynamicEntity {
    void draw_into(sf::RenderWindow& window) override;

    std::unique_ptr<IDynamicEntity> clone() const override { return std::make_unique<Enemy>(*this); }

    void action() override;

    void prepare_for_drawing() override;

    std::unique_ptr<IGameEvent> accept(IVisitor* ptr_visitor) override;
private:
    sf::CircleShape m_enemy_circle;
    sf::Clock stopwatch;
};

struct PacMan : public IEntity, public IVisitor {
    void move(Room::Direction direction);
    void draw_into(sf::RenderWindow& window) override;
    void prepare_for_drawing() override;
    std::unique_ptr<IGameEvent> visit(Food* ptr_food) override;
    std::unique_ptr<IGameEvent> visit(Enemy* ptr_food) override;
private:
    sf::CircleShape m_pacman_circle;
};



