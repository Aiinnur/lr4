#include "Menu.h"
#include "../state/SelectState.h"
#include "../ExitCommand/ExitCommand.h"
#include "../GameCommand/GameCommand.h"
#include "../config/config.h"
#include <memory>
#include "../GameBuilderDirector/GameBuilderDirector.h"
#include "../Builder/SimpleBuilder.h"
#include "../Builder/ComplexBuilder.h"


void Menu::draw_into(sf::RenderWindow& window)
{
	for (auto& ptr_button : m_buttons)
		ptr_button->draw_into(window);
}

void Menu::process_mouse(const sf::Vector2f& pos, bool is_pressed) {//где мышка
	for (auto& button : m_buttons) {
		if (button->is_position_in(pos))
			button->select();
		else
			button->unselect();
		if (is_pressed && button->is_selected())
			button->push();
	}
}

Menu::Menu(IStateManager& state_manager) {
	m_buttons.push_back(std::make_unique<Button>());
	m_buttons.push_back(std::make_unique<Button>());
	m_buttons.push_back(std::make_unique<Button>());
	m_buttons.push_back(std::make_unique<Button>());
    m_buttons[0]->set(sf::Vector2f(200, 160), config::BUTTON_SIZE, config::BUTTON_TEXT_EASY, config::BUTTON_FONT_SIZE, std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
        std::make_unique<SimpleBuilder>(
            config::GAME_VIDEO_MODE_WIDTH,
            config::GAME_VIDEO_MODE_HEIGHT,
            config::ROOM_SIZE),
        config::EASY_GAME_TITLE,
        config::EASY_GAME_ENEMY_RATIO)));
	m_buttons[1]->set(sf::Vector2f(200, 280), config::BUTTON_SIZE, config::BUTTON_TEXT_MEDIUM, config::BUTTON_FONT_SIZE, std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
        std::make_unique<SimpleBuilder>(
            config::GAME_VIDEO_MODE_WIDTH,
            config::GAME_VIDEO_MODE_HEIGHT,
            config::ROOM_SIZE),
        config::EASY_GAME_TITLE,
        config::EASY_GAME_ENEMY_RATIO)));
	m_buttons[2]->set(sf::Vector2f(200, 400), config::BUTTON_SIZE, config::BUTTON_TEXT_HARD, config::BUTTON_FONT_SIZE, std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
        std::make_unique<SimpleBuilder>(
            config::GAME_VIDEO_MODE_WIDTH,
            config::GAME_VIDEO_MODE_HEIGHT,
            config::ROOM_SIZE),
        config::EASY_GAME_TITLE,
        config::EASY_GAME_ENEMY_RATIO)));
	m_buttons[3]->set(sf::Vector2f(200, 520), config::BUTTON_SIZE, config::BUTTON_TEXT_EXIT, config::BUTTON_FONT_SIZE, std::make_unique<GameCommand>(state_manager, std::make_unique<GameBuilderDirector>(
        std::make_unique<SimpleBuilder>(
            config::GAME_VIDEO_MODE_WIDTH,
            config::GAME_VIDEO_MODE_HEIGHT,
            config::ROOM_SIZE),
        config::EASY_GAME_TITLE,
        config::EASY_GAME_ENEMY_RATIO)));
}


/*Menu::Menu(IStateManager& state_manager) {
    float start_position_buttons = 100;
    float delta_position_buttons = config::BUTTON_SIZE.y + 25;

    m_buttons.emplace_back(std::make_unique<Button>(
        sf::Vector2f{ config::SELECT_LEVEL_VIDEO_MODE_WIDTH / 2, start_position_buttons },
        config::BUTTON_SIZE,
        config::BUTTON_TEXT_EASY,
        config::BUTTON_FONT_SIZE,
        std::move(std::make_unique<GameCommand>(
            state_manager, std::make_unique<GameBuilderDirector>(
                std::make_unique<SimpleGameBuilder>(
                    config::GAME_VIDEO_MODE_WIDTH,
                    config::GAME_VIDEO_MODE_HEIGHT,
                    config::ROOM_SIZE),
                config::EASY_GAME_TITLE,
                config::EASY_GAME_ENEMY_RATIO
            )
        ))
    ));

    
        std::move(std::make_unique<GameCommand>(
            state_manager, std::make_unique<GameBuilderDirector>(
                std::make_unique<SimpleGameBuilder>(
                    config::GAME_VIDEO_MODE_WIDTH,
                    config::GAME_VIDEO_MODE_HEIGHT,
                    config::ROOM_SIZE),
                config::MEDIUM_GAME_TITLE,
                config::MEDIUM_GAME_ENEMY_RATIO
            )
        ))
    ));

    m_buttons.emplace_back(std::make_unique<Button>(
        sf::Vector2f{ config::SELECT_LEVEL_VIDEO_MODE_WIDTH / 2,
                      start_position_buttons + delta_position_buttons * 2 },
        config::BUTTON_SIZE,
        config::BUTTON_TEXT_HARD,
        config::BUTTON_FONT_SIZE,
        std::move(std::make_unique<GameCommand>(
            state_manager, std::make_unique<GameBuilderDirector>(
                std::make_unique<ComplexGameBuilder>(
                    config::GAME_VIDEO_MODE_WIDTH,
                    config::GAME_VIDEO_MODE_HEIGHT,
                    config::ROOM_SIZE),
                config::HARD_GAME_TITLE,
                config::HARD_GAME_ENEMY_RATIO
            )
        ))
    ));

    m_buttons.emplace_back(std::make_unique<Button>(
        sf::Vector2f{ config::SELECT_LEVEL_VIDEO_MODE_WIDTH / 2,
                      start_position_buttons + delta_position_buttons * 3 },
        config::BUTTON_SIZE,
        config::BUTTON_TEXT_EXIT,
        config::BUTTON_FONT_SIZE,
        std::move(std::make_unique<ExitCommand>(state_manager)))
    );
}*/

