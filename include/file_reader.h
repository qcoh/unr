#pragma once

#include <iosfwd>
#include <string>

#include "reader.h"

namespace unr
{

class FileReader : public Reader
{
public:
    using Reader::char_type;
    using Reader::offset_type;

    explicit FileReader(const char *);
    virtual ~FileReader();

    FileReader(const FileReader &) = delete;
    FileReader &operator=(const FileReader &) = delete;

    FileReader(Reader &&) = delete;
    FileReader &operator=(FileReader &&) = delete;

    virtual char_type peek() override;
    virtual char_type read() override;
    virtual offset_type seek(offset_type) override;

private:
    FILE* m_file{nullptr};
};

} // namespace unr