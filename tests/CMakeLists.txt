set(SOURCES
	test_main.cpp
	test_parser.cpp
)

add_executable(unr_test
	${SOURCES}
)

target_include_directories(unr_test
	PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(unr_test
	PRIVATE
	Catch2::Catch2
	unr_lib
)

add_test(NAME unr_test COMMAND unr_test)
