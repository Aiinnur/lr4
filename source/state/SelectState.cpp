#include "SelectState.h"
#include "i_state_manager.h"
#include "../state/ExitState.h"
#include "../config/config.h"


SelectState::SelectState(IStateManager& state_manager, const std::string& window_title) :
    m_menu(state_manager),
    IWindowKeeper(config::SELECT_LEVEL_VIDEO_MODE, window_title),
    IState(state_manager) {}


bool SelectState::do_step() {
    event_handling();
    update();
    render();
    return true;
};
void SelectState::event_handling() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
            m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
            break;
        }
        auto coord_mouse = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
        auto is_pressed = event.type == sf::Event::MouseButtonPressed;
        m_menu.process_mouse(coord_mouse, is_pressed);
    }
};

void SelectState::render() {
    m_window.clear(config::SELECT_LEVEL_BACKGROUND_COLOR);
    m_menu.draw_into(m_window);
    m_window.display();
};

void SelectState::update()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    m_menu.process_mouse(sf::Vector2f{ static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) }, sf::Mouse::isButtonPressed(sf::Mouse::Left));
}