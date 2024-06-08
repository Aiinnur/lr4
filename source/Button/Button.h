#pragma once
#include "../IDrawable/IDrawable.h"
#include "../ISelectCommand/ISelectCommand.h"
#include  "../MyFont/MyFont.h"
#include <SFML/Graphics.hpp>

struct Button : public IDrawable
{

public:
	void set(sf::Vector2f pos, sf::Vector2f button_size, std::string text, size_t font_size, std::unique_ptr<ISelectCommand> ptr_command);
	void select() noexcept { m_is_selected = true; }
	void unselect() noexcept { m_is_selected = false; }
	bool is_selected() { return m_is_selected; }
	bool is_position_in(const sf::Vector2f& pos);
	void push();
	void draw_into(sf::RenderWindow& window);

private:;
	bool m_is_selected = false;
	sf::Text m_text;
	sf::RectangleShape m_rectangle;
	std::unique_ptr<ISelectCommand> m_command;

};
