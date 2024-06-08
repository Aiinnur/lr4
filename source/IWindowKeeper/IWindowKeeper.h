#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class IWindowKeeper {
public:
	IWindowKeeper(const sf::VideoMode& mode, const std::string& title);
	virtual ~IWindowKeeper() = default;

protected:
	virtual void event_handling() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	sf::RenderWindow m_window;
};
