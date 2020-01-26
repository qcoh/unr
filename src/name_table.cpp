#include "name_table.h"
#include "parser.h"
#include "reader.h"
#include <iostream>

namespace unr {

NameTable::NameTable(Reader& reader, uoffset offset, usize size)
{
    m_objects.reserve(size);

    reader.seek(offset);

    for (u32 i = 0; i < size; i++) {
        Object object {};

        object.object_name = parse_name(reader);
        object.object_flags = parse_u32(reader);

        m_objects.push_back(object);
    }
}

NameTable::NameTable(NameTable&& other)
    : m_objects { std::move(other.m_objects) }
{
}

NameTable& NameTable::operator=(NameTable&& other)
{
    std::swap(m_objects, other.m_objects);
    return *this;
}

std::optional<NameTable::Object> NameTable::get(uindex index) const noexcept
{
    if (index < m_objects.size()) {
        return m_objects[index];
    }
    return {};
}

void NameTable::dump()
{
    for (const auto& object : m_objects) {
        std::cout << object.object_name << '\n';
    }
}

}