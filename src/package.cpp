#include "package.h"
#include "parser.h"
#include "reader.h"

#include <iostream>

namespace unr {

Package::Package(Reader& reader)
{
    header = deserialize_header(reader);
    name_table = deserialize_name_table(reader, header.name_offset, header.name_count);
    export_table = deserialize_export_table(reader, header.export_offset, header.export_count);
    import_table = deserialize_import_table(reader, header.import_offset, header.import_count);


    for (auto&& object_name : name_table) {
        std::cout << object_name.object_name << '\n';
    }
}

Package::Header Package::deserialize_header(Reader& reader)
{
    Header ret = { 0 };

    ret.signature = parse_u32(reader);
    ret.package_version = parse_u32(reader);
    ret.package_flags = parse_u32(reader);
    ret.name_count = parse_u32(reader);
    ret.name_offset = parse_u32(reader);
    ret.export_count = parse_u32(reader);
    ret.export_offset = parse_u32(reader);
    ret.import_count = parse_u32(reader);
    ret.import_offset = parse_u32(reader);

    return ret;
}

Package::name_table_type Package::deserialize_name_table(Reader& reader, u32 offset, u32 count)
{
    name_table_type ret {};
    ret.reserve(count);

    reader.seek(offset);

    for (u32 i = 0; i < count; i++) {
        ObjectName object_name {};
        object_name.object_name = parse_name(reader);
        object_name.object_flags = parse_u32(reader);

        ret.push_back(object_name);
    }

    return ret;
}

Package::export_table_type Package::deserialize_export_table(Reader& reader, u32 offset, u32 count)
{
    export_table_type ret {};
    ret.reserve(count);

    reader.seek(offset);

    for (u32 i = 0; i < count; i++) {
        ExportObject export_object {};

        export_object.class_ = parse_index(reader);
        export_object.super = parse_index(reader);
        export_object.package = parse_u32(reader);
        export_object.object_name = parse_index(reader);
        export_object.object_flags = parse_u32(reader);
        export_object.serial_size = parse_index(reader);
        export_object.serial_offset = parse_index(reader);
    }

    return ret;
}

Package::import_table_type Package::deserialize_import_table(Reader& reader, u32 offset, u32 count)
{
    import_table_type ret {};
    ret.reserve(count);

    reader.seek(offset);

    for (u32 i = 0; i < count; i++) {
        ImportObject import_object {};

        import_object.class_package = parse_index(reader);
        import_object.class_name = parse_index(reader);
        import_object.package = parse_u32(reader);
        import_object.object_name = parse_index(reader);
    }

    return ret;
}

}