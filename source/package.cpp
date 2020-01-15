#include "package.h"
#include "reader.h"

namespace unr {

Package::Header Package::deserialize_header(Reader& reader) {
    Header ret = {0};

    ret.signature = reader.readDword();
    ret.package_version = reader.readDword();
    ret.package_flags = reader.readDword();
    ret.name_count = reader.readDword();
    ret.name_offset = reader.readDword();
    ret.export_count = reader.readDword();
    ret.export_offset = reader.readDword();
    ret.import_count = reader.readDword();
    ret.import_offset = reader.readDword();

    return ret;
}

Package::name_table_type Package::deserialize_name_table(Reader& reader, Reader::offset_type offset, u32 count) {
    name_table_type ret{};
    ret.reserve(count);

    reader.seek(offset);

    for (u32 i = 0; i < count; i++) {
        ObjectName object_name{};
        object_name.object_name = reader.readName();
        object_name.object_flags = reader.readDword();
    }

    return ret;

    

}

}