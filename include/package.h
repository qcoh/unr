#pragma once

#include "types.h"
#include <vector>
#include <string>

namespace unr {

class Reader;

class Package {
public:
    explicit Package(Reader&);

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

    static name_table_type deserialize_name_table(Reader&, u32, u32);
    
    struct ExportObject {
        u32 class_;
        u32 super;
        u32 package;
        u32 object_name;
        u32 object_flags;
        u32 serial_size;
        u32 serial_offset;
    };

    using export_table_type = std::vector<ExportObject>;
    export_table_type export_table;

    static export_table_type deserialize_export_table(Reader&, u32, u32);


    struct ImportObject {
        u32 class_package;
        u32 class_name;
        u32 package;
        u32 object_name;
    };

    using import_table_type = std::vector<ImportObject>;
    import_table_type import_table;

    static import_table_type deserialize_import_table(Reader&, u32, u32);

};

}
