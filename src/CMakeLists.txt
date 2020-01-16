set(SOURCES
	main.cpp
	package.cpp
	reader.cpp
)

add_executable(unr
	${SOURCES}
)

target_include_directories(unr
	PRIVATE
	${CMAKE_SOURCE_DIR}/include
)
