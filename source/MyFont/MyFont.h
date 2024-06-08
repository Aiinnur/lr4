#include <SFML/Graphics.hpp>
#include <memory>

class MyFont {
private:
    MyFont();
public:
    MyFont(const MyFont&) = delete; // ��������� �����������
    MyFont& operator=(const MyFont&) = delete; // ��������� ������������
    static sf::Font& Instance();
private:
    sf::Font m_font;
};
