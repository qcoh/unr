#include "object_reference.h"
#include "export_table.h"
#include "import_table.h"
#include "name_table.h"
#include <cstring>

namespace unr {

ObjectReference::ObjectReference(u32 ref) noexcept
{
    std::memcpy(&m_ref, &ref, sizeof(ref));
}

std::string ObjectReference::getName(const NameTable& name_table, const ImportTable& import_table, const ExportTable& export_table) const
{
    if (m_ref < 0) {
        u32 index = static_cast<u32>(-m_ref - 1);

        return name_table.get(import_table.get(index)->object_name)->object_name;
    } else if (m_ref > 0) {
        u32 index = static_cast<u32>(m_ref);

        return name_table.get(export_table.get(index)->object_name)->object_name;
    } else {
        return "null";
    }
}

}