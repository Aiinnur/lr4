#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/System.hpp>

struct IDrawable
{
	virtual void draw_into(sf::RenderWindow& window) = 0;
	virtual ~IDrawable() = default;

};
