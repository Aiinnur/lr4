#include "SimpleBuilder.h"

void SimpleBuilder::create_rooms() {
    // ���������� ���������� ������ �� ��� X � Y, ������� ����� ���������� �� ����������� � ���������
    size_t count_of_rooms_x = m_width / m_room_size - 2;
    size_t count_of_rooms_y = m_height / m_room_size - 2;

    // ���������� ���������� ������ �� ��������� �����
    if (count_of_rooms_x % 2 == 0) ++count_of_rooms_x;
    if (count_of_rooms_y % 2 == 0) ++count_of_rooms_y;

    // ����������� ��������� ������� (������ ������ �������) �� X � Y ��� ���������� ����� ������
    auto start_x = (m_width - count_of_rooms_x * m_room_size) / 2.0f + m_room_size / 2.0f;
    auto start_y = (m_height - count_of_rooms_y * m_room_size + m_room_size) / 2.0f;

    // ������ ��� �������� ����� ������ ������
    std::vector<std::unique_ptr<Room>> row_rooms;

    // �������� ����� ������
    for (size_t index_y = 0; index_y < count_of_rooms_y; ++index_y) {
        for (size_t index_x = 0; index_x < count_of_rooms_x; ++index_x) {
            // �������� ����������� ��������� �� �������
            auto room = std::make_unique<Room>(m_room_size);

            // ��������� ������� �������
            room->set_position({ start_x + index_x * m_room_size, start_y + index_y * m_room_size });

            // ���������� ������� � ������� ������
            row_rooms.emplace_back(std::move(room));
        }

        // ����������� ������� ������ � �������� ��������� m_rooms � ������� ���������� ������� row_v
        m_rooms.push_back(std::move(row_rooms));
        row_rooms.clear();
    }
}

