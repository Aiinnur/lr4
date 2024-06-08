#include "Button.h"
#include"../config/config.h"


void Button::set(sf::Vector2f pos, sf::Vector2f button_size, std::string text, size_t font_size, std::unique_ptr<ISelectCommand> ptr_command)
{

    // Устанавливаем размер и позицию прямоугольника кнопки
    /*m_rectangle.setSize(button_size);
    m_rectangle.setPosition(pos);

    // Устанавливаем шрифт для текста
    m_text.setFont(MyFont::Instance());

    // Устанавливаем текст
    m_text.setString(text);
    m_text.setCharacterSize(font_size);
    m_text.setFillColor(config::BUTTON_COLOR_TEXT);

    // Центрирование текста относительно кнопки
    sf::FloatRect text_rect = m_text.getLocalBounds();
    m_text.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
    m_text.setPosition(pos.x + button_size.x / 2.0f, pos.y + button_size.y / 2.0f);

    // Устанавливаем цвет кнопки
    m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
    m_rectangle.setOutlineThickness(config::BUTTON_FRAME_THICKNESS);
    m_rectangle.setOutlineColor(config::BUTTON_COLOR_FRAME);

    // Устанавливаем команду, если это необходимо
    m_command = std::move(ptr_command);

    // Устанавливаем межбуквенный интервал
    m_text.setLetterSpacing(1);*/
    m_rectangle.setSize(button_size);
    m_rectangle.setOrigin({ button_size.x / 2.0f, button_size.y / 2.0f });
    m_rectangle.setPosition(pos);
    m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
    m_rectangle.setOutlineThickness(config::BUTTON_FRAME_THICKNESS);
    m_rectangle.setOutlineColor(config::BUTTON_COLOR_FRAME);
    m_text = sf::Text(text, MyFont::Instance(), font_size);
    sf::FloatRect rect = m_text.getLocalBounds();
    m_text.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    m_text.setPosition(pos);
    m_text.setFillColor(config::BUTTON_COLOR_TEXT);
    m_command = std::move(ptr_command);
}


void Button::draw_into(sf::RenderWindow& window)
{
	if (this->is_selected()) m_rectangle.setFillColor(sf::Color::Green);
	else m_rectangle.setFillColor(sf::Color::Black);
	window.draw(m_rectangle);
	window.draw(m_text);
}

bool Button::is_position_in(const sf::Vector2f& pos)
{
	return m_rectangle.getGlobalBounds().contains(pos);
}

void Button::push()
{
	m_command->execute();
}
