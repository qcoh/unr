#pragma once

#include "types.h"

namespace unr {

class Reader;

struct Header {
    u32 signature;
    u32 package_version;
    u32 package_flags;

    u32 name_count;
    u32 name_offset;

    u32 export_count;
    u32 export_offset;

    u32 import_count;
    u32 import_offset;

    // ignore guid
    // ignore generation

    explicit Header(Reader&);
};

}