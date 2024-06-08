#include "CommonBuilder.h"
#include "../config/config.h"


CommonBuilder::CommonBuilder(float width, float height, float room_size) :
    m_width(width), m_height(height), m_room_size(room_size) {}


void CommonBuilder::set_rooms_sides() {
    using DIR = Room::Direction;

    for (int row_n = 0; row_n < m_rooms.size(); ++row_n) {
        for (int col_n = 0; col_n < m_rooms[row_n].size(); ++col_n) {

            auto& this_room = m_rooms[row_n][col_n];
            if (this_room != nullptr) {
                for (auto dir : { DIR::UP, DIR::LEFT, DIR::DOWN, DIR::RIGHT }) {
                    if (dir == Room::UP && row_n - 1 >= 0 && m_rooms[row_n - 1][col_n] != nullptr) {
                        this_room->set_side(dir, std::make_shared<Pass>(*this_room, *m_rooms[row_n - 1][col_n]));
                    }
                    else if (dir == Room::LEFT && col_n - 1 >= 0 && m_rooms[row_n][col_n - 1] != nullptr) {
                        this_room->set_side(dir, std::make_shared<Pass>(*this_room, *m_rooms[row_n][col_n - 1]));
                    }
                    else if (dir == Room::DOWN && row_n + 1 <= m_rooms.size() - 1 && m_rooms[row_n + 1][col_n] != nullptr) {
                        this_room->set_side(dir, std::make_shared<Pass>(*this_room, *m_rooms[row_n + 1][col_n]));
                    }
                    else if (dir == Room::RIGHT && col_n + 1 <= m_rooms[row_n].size() - 1 && m_rooms[row_n][col_n + 1] != nullptr) {
                        this_room->set_side(dir, std::make_shared<Pass>(*this_room, *m_rooms[row_n][col_n + 1]));
                    }
                    else {
                        this_room->set_side(dir, std::make_shared<Wall>(*this_room));
                    }
                }
            }
        }
    }
}

void CommonBuilder::prepare_available_rooms() {
    for (auto& row : m_rooms) {
        for (auto& room : row) {
            if (room != nullptr) {
                m_available_rooms.push_back(room.get());
            }
        }
    }
}


void CommonBuilder::create_state(IStateManager& state_manager, std::string window_title) {
    m_game_state = std::make_unique<GameState>(state_manager, window_title, sf::VideoMode(m_width, m_height));
}


void CommonBuilder::set_all_to_state() {
    std::vector<std::unique_ptr<Room>> rooms_without_nullptr;
    for (auto& row : m_rooms) {
        for (auto& room : row) {
            if (room != nullptr)
                rooms_without_nullptr.push_back(std::move(room));
        }
    }
    m_game_state->set_maze(Maze(rooms_without_nullptr));
    m_game_state->set_context(std::move(m_context));
}

void CommonBuilder::create_context(float dynamic_objects_ratio) {
    std::random_device rd;
    std::mt19937 generator(rd());

    // Подготовить доступные комнаты
    prepare_available_rooms();

    // Еда
    for (auto& room : m_available_rooms) {
        auto food = std::make_unique<Food>();
        food->set_location(*room);
        m_context.static_objects.push_back(std::move(food));
    }

    // PacMan
    if (!m_available_rooms.empty()) {
        std::uniform_int_distribution<size_t> dist(0, m_available_rooms.size() - 1);
        size_t index = dist(generator);
        PacMan pacman;
        pacman.set_location(*m_available_rooms[index]);
        m_context.pacman = std::move(pacman);

        // Удалить PacMan из списка доступных комнат
        m_available_rooms.erase(m_available_rooms.begin() + index);
    }

    // Враги
    size_t num_enemies = static_cast<size_t>(config::COUNT_ENEMY * dynamic_objects_ratio);
    for (size_t i = 0; i < num_enemies && !m_available_rooms.empty(); ++i) {
        std::uniform_int_distribution<size_t> dist(0, m_available_rooms.size() - 1);// генерирует случайные целые числа в заданном диапазоне, причем все числа в этом диапазоне имеют равную вероятность появления.
        size_t index = dist(generator);
        auto enemy = std::make_unique<Enemy>();
        enemy->set_location(*m_available_rooms[index]);
        //предыдущее местоположение-?
        m_context.dynamic_objects.push_back(std::move(enemy));
        // Удалить врага из списка доступных комнат
        m_available_rooms.erase(m_available_rooms.begin() + index);
    }
}