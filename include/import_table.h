#pragma once

#include "types.h"
#include <optional>
#include <vector>

namespace unr {

class Reader;

class ImportTable {
public:
    struct Object {
        u32 class_package;
        u32 class_name;
        u32 package;
        u32 object_name;
    };

    ImportTable(Reader&, uoffset, usize);
    ~ImportTable() = default;

    ImportTable(const ImportTable&) = delete;
    ImportTable& operator=(const ImportTable&) = delete;

    ImportTable(ImportTable&&);
    ImportTable& operator=(ImportTable&&);

    std::optional<Object> get(uindex) const noexcept;

private:
    std::vector<Object> m_objects {};
};

}