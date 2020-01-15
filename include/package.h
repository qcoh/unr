#pragma once

#include "types.h"
#include <vector>
#include <string>
#include "reader.h"

namespace unr {

class Package {
public:
    static Package deserialize(Reader&);

private:
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
    };

    Header header;

    static Header deserialize_header(Reader&);

    struct ObjectName {
        std::string object_name;
        u32 object_flags;
    };

    using name_table_type = std::vector<ObjectName>;
    name_table_type name_table;

    static name_table_type deserialize_name_table(Reader&, Reader::offset_type, u32);
    
};

}
