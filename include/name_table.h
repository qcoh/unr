#pragma once

#include "types.h"
#include <optional>
#include <vector>

namespace unr {

class Reader;

class NameTable {
public:
    struct Object {
        std::string object_name;
        u32 object_flags;
    };

    NameTable(Reader&, uoffset, usize);
    ~NameTable() = default;

    NameTable(const NameTable&) = delete;
    NameTable& operator=(const NameTable&) = delete;

    NameTable(NameTable&&);
    NameTable& operator=(NameTable&&);

    std::optional<Object> get(uindex) const noexcept;

    void dump();

private:
    std::vector<Object> m_objects {};
};

}