#include "header.h"
#include "parser.h"
#include "reader.h"

namespace unr {

Header::Header(Reader& reader)
{
    signature = parse_u32(reader);
    package_version = parse_u32(reader);
    package_flags = parse_u32(reader);
    name_count = parse_u32(reader);
    name_offset = parse_u32(reader);
    export_count = parse_u32(reader);
    export_offset = parse_u32(reader);
    import_count = parse_u32(reader);
    import_offset = parse_u32(reader);
}

}