#include "SideWallAndPass.h"
#include "../Entity/Entity.h"
#include <thread>
#include <cmath>

sf::Vector2f rotate_vector(const sf::Vector2f& vec, float angle) {
    float radians = angle * 3.14159265 / 180.0; // ������������ ���� � �������
    float cosine = std::cos(radians);
    float sine = std::sin(radians);
    return sf::Vector2f(
        vec.x * cosine - vec.y * sine,
        vec.x * sine + vec.y * cosine
    );
}

void Wall::draw_into(sf::RenderWindow& window) {
    prepare_for_drawing();//???????????
    // �������� ����������� ����� ������������ �������
    auto dir = m_room.get_direction(*this);
    // �������� �������� ������� ������� (������)
    auto size = m_room.get_size() / 2;
    // �������� ������� ������� (����������� �������)
    auto pos = m_room.get_position();
    // ������� ��������� ������, ��������� �� �������� ������� ������� �����
    auto vec = sf::Vector2f{ -size, 0 };
    // ������������ ������ �� 90 �������� ���������� �� ����������� ����� (����� ���� 0, 90, 180 ��� 270 ��������)
    auto rotate_vec = rotate_vector(vec, 90 * static_cast<int>(dir));
    // ������������ ���������� ������ ��� �� 90 �������� ��� ��������� ����������������� �������
    auto rotate_vec2 = rotate_vector(rotate_vec, 90);
    // ��������� ������ ����� �����, ������� �������� ������� �� ��� �������� �������
    auto pos0 = pos + rotate_vec + rotate_vec2;
    // ��������� ������ ����� �����, ������� �������� ������� �� ���� ������� � ������� ������ ������� �������
    auto pos1 = pos + rotate_vec - rotate_vec2;

    // ������ ����� ����� � ������� m_line
    m_line[0] = pos0;
    m_line[1] = pos1;
    window.draw(m_line, 2, sf::Lines);
}

void Wall::prepare_for_drawing() {
    auto dir = m_room.get_direction(*this);
    m_room.set_side(dir, std::shared_ptr<IRoomSide>(this));

}

bool Wall::enter(IEntity& entity) {
    return false;
}

bool Pass::enter(IEntity& entity) {
    entity.set_location(&entity.get_location() == &m_room2 ? m_room1 : m_room2);
    return true;
}
