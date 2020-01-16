#include "reader.h"

#include <cstdio>
#include <stdexcept>
#include <cstring>

namespace unr {

Reader::Reader(const char* filename) {
    m_file = std::fopen(filename, "r");

    if (!m_file) {
        throw std::runtime_error{"Unable to open file"};
    }
}

Reader::~Reader() {
    if (m_file) {
        fclose(m_file);
        m_file = nullptr;
    }
}

Reader::Reader(Reader&& other) {
    m_file = other.m_file;
    other.m_file = nullptr;
}

Reader& Reader::operator=(Reader&& other) {
    m_file = other.m_file;
    other.m_file = nullptr;

    return *this;
}

Reader::char_type Reader::peekChar() {
    char_type c = readChar();
    ungetc(c, m_file);
    return c;
}

Reader::char_type Reader::readChar() {
    return static_cast<char_type>(fgetc(m_file));
}

Reader::dword_type Reader::readDword() {
    dword_type ret = 0;
    char_type buf[4] = {0};
    fread(buf, 4, 1, m_file);

    memcpy(&ret, buf, 4);
    return ret;
}

Reader::name_type Reader::readName() {
    std::string ret{};

    char_type length = this->readChar();

    for (char_type i = /* not an error: */ 1; i < length; i++) {
        ret.push_back(this->readChar());
    }

    // read zero byte at the end
    (void)this->readChar();

    return ret;
}

Reader::index_type Reader::readIndex() {
    index_type ret = 0;

    const char_type first = this->readChar();
    ret |= first & 0b00111111;

    if (!(first & 0b01000000)) {
        return (first & 0b10000000) ? -ret : ret;
    }

    const char_type second = this->readChar();
    ret |= (second & 0b01111111) << 6;

    // TODO: finish this :/
    return ret;
}


Reader::offset_type Reader::seek(Reader::offset_type offset) {
    return static_cast<offset_type>(fseek(m_file, offset, SEEK_SET));
}


}
