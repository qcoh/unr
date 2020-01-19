#pragma once

namespace unr {

class Reader {
public:
    using char_type = unsigned char;
    using offset_type = long;

    Reader() = default;
    virtual ~Reader() = default;

    virtual char_type peek() = 0;
    virtual char_type read() = 0;
    virtual offset_type seek(offset_type) = 0;

    Reader(const Reader&) = delete;
    Reader& operator=(const Reader&) = delete;
    Reader(Reader&&) = delete;
    Reader& operator=(Reader&&) = delete;
};

}