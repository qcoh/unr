set(SOURCES
	package.cpp
	file_reader.cpp
	parser.cpp
)

add_library(unr_lib
	STATIC
	${SOURCES}
)

target_include_directories(unr_lib
	PUBLIC
	${CMAKE_SOURCE_DIR}/include	
)

# executable:

add_executable(unr
	main.cpp
)

target_link_libraries(unr
	PRIVATE
	unr_lib
)

target_include_directories(unr
	PRIVATE
	${CMAKE_SOURCE_DIR}/include
)
