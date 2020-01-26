#pragma once

#include "export_table.h"
#include "header.h"
#include "import_table.h"
#include "name_table.h"
#include "types.h"
#include <string>
#include <vector>

namespace unr {

class Reader;

class Package {
public:
    explicit Package(Reader&);

private:
    Header m_header;
    NameTable m_name_table;
    ImportTable m_import_table;
    ExportTable m_export_table;
};

}
