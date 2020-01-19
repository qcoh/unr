set(SOURCES
	main.cpp
	package.cpp
	file_reader.cpp
	parser.cpp
)

add_executable(unr
	${SOURCES}
)

target_include_directories(unr
	PRIVATE
	${CMAKE_SOURCE_DIR}/include
)
