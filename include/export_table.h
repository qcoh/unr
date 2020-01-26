#pragma once

#include "types.h"
#include <optional>
#include <vector>

namespace unr {

class Reader;

class ExportTable {
public:
    struct Object {
        uindex class_;
        uindex super;
        u32 package;
        uindex object_name;
        u32 object_flags;
        uindex serial_size;
        uindex serial_offset;
    };

    ExportTable(Reader&, uoffset, usize);
    ~ExportTable() = default;

    ExportTable(const ExportTable&) = delete;
    ExportTable& operator=(const ExportTable&) = delete;

    ExportTable(ExportTable&&);
    ExportTable& operator=(ExportTable&&);

    std::optional<Object> get(uindex) const noexcept;

private:
    std::vector<Object> m_objects {};
};

}