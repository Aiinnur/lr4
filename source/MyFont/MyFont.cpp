#pragma once
#include "MyFont.h"
sf::Font& MyFont::Instance() {
	static MyFont instance; // Создаем статический объект MyFont
	return instance.m_font; // Возвращаем ссылку на m_font
}
MyFont::MyFont() {
	if (!m_font.loadFromFile(ASSETS_PATH "AnimeAce.ttf")) {
		throw std::runtime_error("Failed to load font");
	}
}

