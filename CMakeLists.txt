cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE PROJ_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE LIBFT_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "libft/*.c")

project(parser C)
set(CMAKE_C_STANDARD 99)

include_directories("includes")
include_directories("libft/includes")

add_executable(parser ${PROJ_SOURCES} ${LIBFT_SOURCES} src/main.c)

#target_link_libraries(parser "-pthread")
#target_link_libraries(parser "-lmlx")
#target_link_libraries(parser "-framework OpenGl")
#target_link_libraries(parser "-framework Appkit")

