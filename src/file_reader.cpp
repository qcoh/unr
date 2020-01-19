#include "file_reader.h"

#include <cstdio>
#include <cstring>
#include <stdexcept>

namespace unr {

FileReader::FileReader(const char* filename)
    : Reader()
{
    m_file = std::fopen(filename, "r");

    if (!m_file) {
        throw std::runtime_error { "Unable to open file" };
    }
}

FileReader::~FileReader()
{
    if (m_file) {
        fclose(m_file);
        m_file = nullptr;
    }
}

FileReader::char_type FileReader::peek()
{
    char_type c = read();
    ungetc(c, m_file);
    return c;
}

FileReader::char_type FileReader::read()
{
    return static_cast<char_type>(fgetc(m_file));
}

FileReader::offset_type FileReader::seek(FileReader::offset_type offset)
{
    return static_cast<offset_type>(fseek(m_file, offset, SEEK_SET));
}

}
