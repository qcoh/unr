set(SOURCES
	test_main.cpp
	example.cpp
)

add_executable(unr_test
	${SOURCES}
)

target_link_libraries(unr_test
	PRIVATE
	Catch2::Catch2
)

add_test(NAME unr_test COMMAND unr_test)
