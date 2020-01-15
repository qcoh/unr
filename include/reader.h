#pragma once

#include <iosfwd>
#include <string>

namespace unr
{

class Reader
{
public:
    using char_type = unsigned char;
    using dword_type = unsigned int;
    using offset_type = long;
    using name_type = std::string;
    using index_type = unsigned int;

    Reader(const char *);
    ~Reader();

    Reader(const Reader &) = delete;
    Reader &operator=(const Reader &) = delete;

    Reader(Reader &&);
    Reader &operator=(Reader &&);

    char_type peekChar();
    char_type readChar();

    dword_type readDword();

    name_type readName();
    
    index_type readIndex();

    offset_type seek(offset_type);

private:
    FILE* m_file{nullptr};
};

} // namespace unr