#include "package.h"
#include "parser.h"
#include "reader.h"

namespace unr {

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

Package::name_table_type Package::deserialize_name_table(Reader& reader, Reader::offset_type offset, u32 count)
{
    name_table_type ret {};
    ret.reserve(count);

    reader.seek(offset);

    for (u32 i = 0; i < count; i++) {
        ObjectName object_name {};
        object_name.object_name = parse_name(reader);
        object_name.object_flags = parse_u32(reader);
    }

    return ret;
}

}