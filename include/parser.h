#pragma once

#include "types.h"
#include <string>

namespace unr {

class Reader;

u32 parse_u32(Reader&);
std::string parse_name(Reader&);
u32 parse_index(Reader&);

}