#include "catch2/catch.hpp"

#include "mock_reader.h"
#include "parser.h"
#include "types.h"

// See UT_Package_File_Format.pdf

SCENARIO("parsing unr package types", "[parser]")
{
    GIVEN("reader with serialized u32")
    {
        test::MockReader reader;

        reader.buffer[0] = 0x11;
        reader.buffer[1] = 0x22;
        reader.buffer[2] = 0x33;
        reader.buffer[3] = 0x44;

        WHEN("parsing u32")
        {
            u32 value = unr::parse_u32(reader);

            THEN("the parsed u32 has correct endianness")
            {
                REQUIRE(value == 0x44332211);
            }
            THEN("the internal index points after the read value")
            {
                REQUIRE(reader.index == 4);
            }
        }
    }

    GIVEN("reader with serialized name")
    {
        test::MockReader reader;

        reader.buffer[0] = 0x7;
        reader.buffer[1] = 'U';
        reader.buffer[2] = 'n';
        reader.buffer[3] = 'r';
        reader.buffer[4] = 'e';
        reader.buffer[5] = 'a';
        reader.buffer[6] = 'l';
        reader.buffer[7] = 0x0;

        WHEN("parsing the name")
        {
            std::string name = unr::parse_name(reader);

            THEN("the correct name is parsed")
            {
                REQUIRE(name == "Unreal");
            }
            THEN("the internal index points after the read name")
            {
                REQUIRE(reader.index == 8);
            }
        }
    }

    GIVEN("reader with serialized index")
    {
        test::MockReader reader;

        reader.buffer[0] = 0xf9;
        reader.buffer[1] = 0xc0;
        reader.buffer[2] = 0x01;

        WHEN("parsing the index")
        {
            u32 index = unr::parse_index(reader);

            THEN("the correct value is parsed")
            {
                REQUIRE(index == -12345);
            }
            THEN("the internal index points after the read value")
            {
                REQUIRE(reader.index == 3);
            }
        }
    }
}