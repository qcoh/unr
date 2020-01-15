#pragma once

namespace unr {

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;

static_assert(sizeof(u8) == 1);
static_assert(sizeof(u16) == 2);
static_assert(sizeof(u32) == 4);

}