#include "Entity.h"
#include "../RoomAndMaze/RoomAndMaze.h"
#include "../config/config.h"
#include <memory>

/// ДОДЕЛАТЬ 
/*void PacMan::draw_into(sf::RenderWindow& window) {
    auto size = config::GAME_PACMAN_SIZE;
    auto pacman_circle = sf::CircleShape(size);
    pacman_circle.setFillColor(config::GAME_COLOR_PACMAN);
    pacman_circle.setOrigin(size, size);
    pacman_circle.setPosition(m_ptr_room->get_position());
    window.draw(pacman_circle);
}
void PacMan::move(Room::Direction direction) {
    m_ptr_room->get_side(direction).enter(*this);
}
void Food::draw_into(sf::RenderWindow& window) {
    float size = config::GAME_FOOD_SIZE;
    auto food_circle = sf::CircleShape(size);
    food_circle.setFillColor(config::GAME_FOOD_COLOR);
    food_circle.setOrigin(size, size);
    food_circle.setPosition(m_ptr_room->get_position());
    window.draw(food_circle);
}
void Enemy::action() {
    auto miliseconds = static_cast<size_t>(stopwatch.getElapsedTime().asMilliseconds());
    if (miliseconds < rand() % 10000)
        return; // Т.е. враг бездействует
    auto direction = static_cast<Room::Direction>(rand() % 4);
    m_ptr_room->get_side(direction).enter(*this);
    stopwatch.restart();
}
void Enemy::draw_into(sf::RenderWindow& window) {
    float size = config::GAME_ENEMY_SIZE / 2;
    auto enemy_circle = sf::CircleShape(size);
    enemy_circle.setFillColor(config::GAME_ENEMY_COLOR);
    enemy_circle.setOrigin(size, size);
    enemy_circle.setPosition(m_ptr_room->get_position());
    window.draw(enemy_circle);
}
__________*/

void PacMan::draw_into(sf::RenderWindow& window) {
    window.draw(m_pacman_circle);
}

void PacMan::move(Room::Direction direction) {
    m_ptr_room->get_side(direction).enter(*this);
    prepare_for_drawing(); // Call prepare_to_draw after moving
}

void PacMan::prepare_for_drawing() {
    auto size = config::GAME_PACMAN_SIZE;
    m_pacman_circle.setRadius(size);
    m_pacman_circle.setFillColor(config::GAME_COLOR_PACMAN);
    m_pacman_circle.setOrigin(size, size);
    m_pacman_circle.setPosition(m_ptr_room->get_position());
}

void Food::draw_into(sf::RenderWindow& window) {
    window.draw(m_food_circle);
}

void Food::prepare_for_drawing() {
    float size = config::GAME_FOOD_SIZE;
    m_food_circle.setRadius(size);
    m_food_circle.setFillColor(config::GAME_FOOD_COLOR);
    m_food_circle.setOrigin(size, size);
    m_food_circle.setPosition(m_ptr_room->get_position());
}

void Enemy::draw_into(sf::RenderWindow& window) {
    window.draw(m_enemy_circle);
}

void Enemy::action() {
    auto miliseconds = static_cast<size_t>(stopwatch.getElapsedTime().asMilliseconds());
    if (miliseconds < rand() % 10000) {
        return; // Враг бездействует
    }
    auto direction = static_cast<Room::Direction>(rand() % 4);
    m_ptr_room->get_side(direction).enter(*this);
    stopwatch.restart();
    prepare_for_drawing(); // Call prepare_to_draw after action
}

void Enemy::prepare_for_drawing() {
    float size = config::GAME_ENEMY_SIZE / 2;
    m_enemy_circle.setRadius(size);
    m_enemy_circle.setFillColor(config::GAME_ENEMY_COLOR);
    m_enemy_circle.setOrigin(size, size);
    m_enemy_circle.setPosition(m_ptr_room->get_position());
}
std::unique_ptr<IGameEvent> PacMan::visit(Food* ptr_food) {
    /*if (ptr_food->get_location() != this->get_location())
        return {};*/
    return std::make_unique<DeleteStaticEntity>(ptr_food);
}

std::unique_ptr<IGameEvent> PacMan::visit(Enemy* ptr_enemy) {
    return std::make_unique<LostGame>();
}
std::unique_ptr<IGameEvent> Food::accept(IVisitor* ptr_visitor) {
    return ptr_visitor->visit(this);
}
std::unique_ptr<IGameEvent> Enemy::accept(IVisitor* ptr_visitor) {
    return ptr_visitor->visit(this);
}
