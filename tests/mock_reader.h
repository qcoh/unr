#pragma once

#include "reader.h"

namespace test {

class MockReader : public unr::Reader {
public:
    using Reader::char_type;
    using Reader::offset_type;
    
    offset_type index = 0;
    char_type buffer[128] = {0};

    MockReader() = default;
    virtual ~MockReader() = default;

    virtual char_type peek() override {
        return buffer[index];
    }
    virtual char_type read() override {
        return buffer[index++];
    }
    virtual offset_type seek(offset_type offset) override {
        index = offset;
        return index;
    }
};

}