#pragma once
#include "../IDrawable/IDrawable.h"
#include "../Button/Button.h"
#include "../state/i_state_manager.h"
#include <SFML/Graphics.hpp>
#include <vector>



struct Menu : public IDrawable
{
public:
	Menu(IStateManager& state_manager);
	void draw_into(sf::RenderWindow& window) override;
	void process_mouse(const sf::Vector2f& pos, bool is_pressed);
private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};
