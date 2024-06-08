#include <SFML/Graphics.hpp>
#include <memory>

class MyFont {
private:
    MyFont();
public:
    MyFont(const MyFont&) = delete; // Запрещаем копирование
    MyFont& operator=(const MyFont&) = delete; // Запрещаем присваивание
    static sf::Font& Instance();
private:
    sf::Font m_font;
};
