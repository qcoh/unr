#include "export_table.h"
#include "name_table.h"
#include "parser.h"
#include "reader.h"
#include <iostream>

namespace unr {

ExportTable::ExportTable(Reader& reader, uoffset offset, usize size)
{
    m_objects.reserve(size);

    reader.seek(offset);

    for (u32 i = 0; i < size; i++) {
        Object object {};

        object.class_ = parse_index(reader);
        object.super = parse_index(reader);
        object.package = parse_u32(reader);
        object.object_name = parse_index(reader);
        object.object_flags = parse_u32(reader);
        object.serial_size = parse_index(reader);
        object.serial_offset = parse_index(reader);

        m_objects.push_back(object);
    }
}

ExportTable::ExportTable(ExportTable&& other)
    : m_objects { std::move(other.m_objects) }
{
}

ExportTable& ExportTable::operator=(ExportTable&& other)
{
    std::swap(m_objects, other.m_objects);
    return *this;
}

std::optional<ExportTable::Object> ExportTable::get(uindex index) const noexcept
{
    if (index < m_objects.size()) {
        return m_objects[index];
    }
    return {};
}

void ExportTable::dump(const NameTable& name_table)
{
    std::cout << "Export Table:\n";
    for (const auto& object : m_objects) {
        std::cout << "Object Name: " << name_table.get(object.object_name)->object_name << '\n';
    }
}

}