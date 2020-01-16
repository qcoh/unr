#include "catch2/catch.hpp"

SCENARIO("foo", "[foo]") {
	GIVEN("an integer") {
		int a = 123;

		REQUIRE(a == 124);	
	}
}
