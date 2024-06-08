#include "SimpleBuilder.h"

void SimpleBuilder::create_rooms() {
    // ¬ычисление количества комнат по оси X и Y, которые можно разместить по горизонтали и вертикали
    size_t count_of_rooms_x = m_width / m_room_size - 2;
    size_t count_of_rooms_y = m_height / m_room_size - 2;

    // ”величение количества комнат до нечетного числа
    if (count_of_rooms_x % 2 == 0) ++count_of_rooms_x;
    if (count_of_rooms_y % 2 == 0) ++count_of_rooms_y;

    // ќпределение начальной позиции (центра первой комнаты) по X и Y дл€ размещени€ сетки комнат
    auto start_x = (m_width - count_of_rooms_x * m_room_size) / 2.0f + m_room_size / 2.0f;
    auto start_y = (m_height - count_of_rooms_y * m_room_size + m_room_size) / 2.0f;

    // ¬ектор дл€ хранени€ одной строки комнат
    std::vector<std::unique_ptr<Room>> row_rooms;

    // —оздание сетки комнат
    for (size_t index_y = 0; index_y < count_of_rooms_y; ++index_y) {
        for (size_t index_x = 0; index_x < count_of_rooms_x; ++index_x) {
            // —оздание уникального указател€ на комнату
            auto room = std::make_unique<Room>(m_room_size);

            // ”становка позиции комнаты
            room->set_position({ start_x + index_x * m_room_size, start_y + index_y * m_room_size });

            // ƒобавление комнаты в текущую строку
            row_rooms.emplace_back(std::move(room));
        }

        // ѕеремещение текущей строки в основной контейнер m_rooms и очистка временного вектора row_v
        m_rooms.push_back(std::move(row_rooms));
        row_rooms.clear();
    }
}

