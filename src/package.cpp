#include "package.h"
#include "parser.h"
#include "reader.h"

#include <algorithm>
#include <iostream>

namespace unr {

Package::Package(Reader& reader)
    : m_header { reader }
    , m_name_table { reader, m_header.name_offset, m_header.name_count }
    , m_import_table { reader, m_header.import_offset, m_header.import_count }
    , m_export_table { reader, m_header.export_offset, m_header.export_count }
{
    m_name_table.dump();
    m_export_table.dump(m_name_table);
}

}