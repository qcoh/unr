#pragma once

#include "types.h"
#include <string>

namespace unr {

class NameTable;
class ImportTable;
class ExportTable;

class ObjectReference final {
public:
    explicit ObjectReference(u32) noexcept;
    ~ObjectReference() = default;

    std::string getName(const NameTable&, const ImportTable&, const ExportTable&) const;

private:
    using ref_type = signed int;
    static_assert(sizeof(ref_type) == sizeof(u32));

    ref_type m_ref { 0 };
};

}