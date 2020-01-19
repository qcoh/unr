#include "catch2/catch.hpp"

#include "types.h"
#include "parser.h"
#include "mock_reader.h"

SCENARIO("parsing unr package types", "[parser]") {
    GIVEN("reader") {
        test::MockReader reader;

        reader.buffer[0] = 0x11;
        reader.buffer[1] = 0x22;
        reader.buffer[2] = 0x33;
        reader.buffer[3] = 0x44;

        WHEN("parsing u32") {
            u32 value = unr::parse_u32(reader);

            THEN("the parsed u32 has correct endianness") {
                REQUIRE(value == 0x44332211);
            }
        }
    }
}