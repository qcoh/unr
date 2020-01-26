#include "export_table.h"
#include "import_table.h"
#include "name_table.h"
#include "object_reference.h"
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

// void dumpObject(Reader& reader, usize size, uoffset offset)
// {

// }

void ExportTable::dump(const NameTable& name_table, const ImportTable& import_table)
{
    std::cout << "Export Table:\n";
    for (const auto& object : m_objects) {
        ObjectReference class_ { object.class_ };

        std::cout << "Class: " << class_.getName(name_table, import_table, *this) << '\n';
        std::cout << "Super: " << ObjectReference { object.super }.getName(name_table, import_table, *this) << '\n';
        std::cout << "Package: " << ObjectReference { object.package }.getName(name_table, import_table, *this) << '\n';
        std::cout << "Name: " << name_table.get(object.object_name)->object_name << "\n";
        std::cout << "Size: " << std::hex << object.serial_size << '\n';
        std::cout << "Offset: " << std::hex << object.serial_offset << "\n\n";

        // if (class_.getName(name_table, import_table, *this) == "Brush") {
        //     dumpObject(reader, object.serial_size, object.serial_offset);
        // }
    }
}

}