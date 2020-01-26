#pragma once

#include "types.h"
#include <optional>
#include <vector>

namespace unr {

class Reader;

class NameTable {
public:
    struct Object {
        u32 class_package;
        u32 class_name;
        u32 package;
        u32 object_name;
    };

    NameTable(Reader&, uoffset, usize);
    ~NameTable() = default;

    NameTable(const NameTable&) = delete;
    NameTable& operator=(const NameTable&) = delete;

    NameTable(NameTable&&);
    NameTable& operator=(NameTable&&);

    std::optional<Object> get(uindex) const noexcept;

private:
    std::vector<Object> m_objects {};
};

}