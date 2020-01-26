#pragma once

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;

using usize = u32;
using uoffset = u32;
using uindex = u32;

static_assert(sizeof(u8) == 1);
static_assert(sizeof(u16) == 2);
static_assert(sizeof(u32) == 4);