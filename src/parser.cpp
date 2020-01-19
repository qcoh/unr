#include "parser.h"
#include "reader.h"

namespace unr {

u32 parse_u32(Reader& reader)
{
    u32 ret = reader.read() | (reader.read() << 8) | (reader.read() << 16) | (reader.read() << 24);
    return ret;
}

std::string parse_name(Reader& reader)
{
    std::string ret {};

    u8 length = reader.read();

    for (u8 i = /* not an error: */ 1; i < length; i++) {
        ret.push_back(static_cast<char>(reader.read()));
    }

    // read zero byte at the end
    (void)reader.read();

    return ret;
}

u32 parse_index(Reader& reader)
{
    u32 ret = 0;

    const u8 first = reader.read();
    ret |= first & 0b00111111;

    if (!(first & 0b01000000)) {
        return (first & 0b10000000) ? -ret : ret;
    }

    const u8 second = reader.read();
    ret |= (second & 0b01111111) << 6;

    if (!(second & 0b10000000)) {
        return (first & 0b10000000) ? -ret : ret;
    }

    const u8 third = reader.read();
    ret |= (third & 0b01111111) << 13;

    if (!(third & 0b10000000)) {
        return (first & 0b10000000) ? -ret : ret;
    }

    const u8 fourth = reader.read();
    ret |= (fourth & 0b01111111) << 20;

    if (!(fourth & 0b10000000)) {
        return (first & 0b10000000) ? -ret : ret;
    }

    const u8 fifth = reader.read();
    ret |= (fifth & 0b01111111) << 27;
    
    return ret;
}

}